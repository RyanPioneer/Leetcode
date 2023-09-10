/**
 * Source: https://rb.gy/52ch0
 * Date: 2023/9/10
 * Skill:
 * Runtime: 40 ms, faster than 47.60% of C++ online submissions
 * Memory Usage: 20.04 MB, less than 75.25% of C++ online submissions
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
    string longestPrefix(string s) {
        vector<int> dp(s.length());
        for (int i = 1; i < s.length(); i++) {
            int j = dp[i - 1];
            while (j > 0 && s[j] != s[i])
                j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        return s.substr(0, dp[(int)s.length() - 1]);
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
    string ss = "level";
    string res = s.longestPrefix(ss);
    cout << res << endl;
}