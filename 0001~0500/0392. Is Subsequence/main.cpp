/** 
 * Source: https://leetcode.com/problems/is-subsequence/
 * Date: 2021/7/12
 * return true if s is a subsequence of t, or false otherwise.
 * 0 <= s.length <= 100
 * 0 <= t.length <= 104
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0)
            return true;
        if(t.length() == 0)
            return false;
        int index = 0;
        for(int i = 0; i < t.length(); i++) {
            if(t[i] == s[index]) {
                index++;
                if(index == s.length())
                    return true;
            }
        }
        return false;
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