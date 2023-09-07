/**
 * Source: https://rb.gy/596fp
 * Date: 2023/9/7
 * Skill:
 * Runtime: 96 ms, faster than 45.51% of C++ online submissions
 * Memory Usage: 7.72 MB, less than 25.28% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= s.length <= 200
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


class Solution {
    int mod = 1e9+7, n;
    string s;
public:
    int numPermsDISequence(string s) {
        s = "I" + s;
        this->s = s;
        n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<bool> visited(n, false);
        return dfs(0, -1, visited, dp) % mod;
    }
    ll dfs(int pos, int last_num, vector<bool>& visited, vector<vector<int>>& dp) {
        if (pos == n)
            return 1;
        ll res = 0;
        int dir = (s[pos] == 'I') ? 1 : -1;
        for (int i = last_num + dir; i >= 0 && i < n; i += dir) {
            if (!visited[i]) {
                if (dp[pos][i] != -1)
                    res = (res + dp[pos][i]) % mod;
                else {
                    visited[i] = true;
                    ll num = dfs(pos + 1, i, visited, dp);
                    dp[pos][i] = num;
                    visited[i] = false;
                    res = (res + dp[pos][i]) % mod;
                }
            }
        }
        return res;
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
    string ss = "DID";
    int res = s.numPermsDISequence(ss);
    cout << res << std::endl;
}