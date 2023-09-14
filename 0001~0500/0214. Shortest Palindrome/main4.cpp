/**
 * Source: https://rb.gy/b3ong
 * Date: 2023/9/14
 * Skill: KMP
 * Runtime: 12 ms, faster than 25.56% of C++ online submissions
 * Memory Usage: 9.95 MB, less than 64.92% of C++ online submissions
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
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    string shortestPalindrome(string s) {
        if (s == "")
            return s;
        int sz = s.length();
        string r = s;
        reverse(begin(r), end(r));
        vector<int> suf = preprocessing(s);
        vector<int> dp(sz);
        if (r[0] == s[0])
            dp[0] = 1;
        for (int i = 1; i < sz; i++) {
            int j = dp[i - 1];
            while (j > 0 && r[i] != s[j])
                j = suf[j - 1];
            dp[i] = j + (r[i] == s[j]);
        }
        string res = s.substr(dp[sz - 1]);
        reverse(begin(res), end(res));
        return res + s;
    }
    vector<int> preprocessing(string s) {
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            int j = dp[i - 1];
            while (j > 0 && s[j] != s[i])
                j = dp[j - 1];
            dp[i] = j + (s[j] == s[i]);
        }
        return dp;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}