/**
 * Source: https://rb.gy/talj8
 * Date: 2023/9/16
 * Skill:
 * Runtime: 12 ms, faster than 59.08% of C++ online submissions
 * Memory Usage: 9.12 MB, less than 18.17% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> q;
        for (auto c: num) {
            while (!q.empty() && k > 0 && q.back() > c) {
                q.pop_back();
                k--;
            }
            q.push_back(c);
        }
        for (int i = 0; i < k; i++)
            q.pop_back();
        string res;
        while (!q.empty() && q.front() == '0')
            q.pop_front();
        if (q.empty())
            return "0";
        while (!q.empty()) {
            res += q.front();
            q.pop_front();
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}