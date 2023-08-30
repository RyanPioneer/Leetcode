/**
 * Source: https://rb.gy/bod0x
 * Date: 2023/8/30
 * Skill:
 * Runtime: 8 ms, faster than 91.18% of C++ online submissions
 * Memory Usage: 8.82 MB, less than 59.56% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= board.length == board[i].length <= 100
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        ll mod = 1e9+7;
        int n = board.size();
        vector<vector<pairs>> dp(n, vector<pairs>(n, {0, 0}));
        dp[n-1][n-1] = {0, 1};
        for (int i = n - 2; i >= 0; i--) {
            if (board[n - 1][i] == 'X' || dp[n - 1][i + 1].second == 0)
                dp[n - 1][i] = {0, 0};
            else
                dp[n - 1][i] = {dp[n - 1][i + 1].first + (board[n - 1][i] - '0'), dp[n - 1][i + 1].second};
            if (board[i][n - 1] == 'X' || dp[i + 1][n - 1].second == 0)
                dp[i][n - 1] = {0, 0};
            else
                dp[i][n - 1] = {dp[i + 1][n - 1].first + (board[i][n - 1] - '0'), dp[i + 1][n - 1].second};
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                if (board[i][j] == 'X')
                    continue;
                ll max_sum = 0, count = 0;
                if (dp[i + 1][j + 1].first > max_sum) {
                    max_sum = dp[i + 1][j + 1].first;
                    count = dp[i + 1][j + 1].second;
                } else if (dp[i + 1][j + 1].first == max_sum) {
                    count += dp[i + 1][j + 1].second;
                }
                if (dp[i + 1][j].first > max_sum) {
                    max_sum = dp[i + 1][j].first;
                    count = dp[i + 1][j].second;
                } else if (dp[i + 1][j].first == max_sum) {
                    count += dp[i + 1][j].second;
                }
                if (dp[i][j + 1].first > max_sum) {
                    max_sum = dp[i][j + 1].first;
                    count = dp[i][j + 1].second;
                } else if (dp[i][j + 1].first == max_sum) {
                    count += dp[i][j + 1].second;
                }
                if (count == 0) {
                    dp[i][j] = {0, 0};
                }else if (i == 0 && j == 0) {
                    dp[i][j] = {max_sum, count % mod};
                } else {
                    dp[i][j] = {max_sum + (board[i][j] - '0'), count % mod};
                }
            }
        }
        vector<int> res{dp[0][0].first, dp[0][0].second};
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
    vector<vector<int>> graph{{1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1}};
    vector<int> initial{3, 1};
}