/** 
 * Source: https://leetcode.com/problems/generate-parentheses/
 * Date: 2021/7/13
 * Skill: DFS
 * 1 <= n <= 8
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string>ans;
    vector<string> generateParenthesis(int n) {
        string s;
        cal(0, 0, n, s);
        return ans;
    }
    void cal(int l, int r, int n, string s) {
        if(l == n && r == n) {
            ans.push_back(s);
            return;
        } else {
            if(l > r) {
                s.push_back(')');
                cal(l, r+1, n, s);
                s.pop_back();
            }
            if(l < n) {
                s.push_back('(');
                cal(l+1, r, n, s);
            }
        }
    }
};

int main() {
   
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();