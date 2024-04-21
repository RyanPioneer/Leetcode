/**
 * Source: is.gd/Dr4nmN
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: TLE
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;
typedef pair<int, int> PII;
const int MX = 501;


class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& Edges, int s, int d, int k) {
        int dp[MX][MX], visited[MX] = {0}, res = INT32_MAX;

        fill(dp[0], dp[MX - 1] + MX, INT32_MAX / 2);
        dp[s][0] = 0;

        vector<PII> edges[MX];

        for (auto &e: Edges) {
            edges[e[0]].push_back({e[1], e[2]});
            edges[e[1]].push_back({e[0], e[2]});
        }

        function<void(int, int)> dfs = [&](int cur, int num) {
            if (cur == d) {
                res = min(res, dp[cur][num]);
                return;
            }
            for (auto &e: edges[cur]) {
                if (visited[e.first]) continue;
                if (dp[cur][num] + e.second < dp[e.first][num] && dp[cur][num] + e.second < res) {
                    visited[e.first] = 1;
                    dp[e.first][num] = dp[cur][num] + e.second;
                    dfs(e.first, num);
                    visited[e.first] = 0;
                }
                if (num < k && dp[cur][num] < dp[e.first][num + 1]) {
                    visited[e.first] = 1;
                    dp[e.first][num + 1] = dp[cur][num];
                    dfs(e.first, num + 1);
                    visited[e.first] = 0;
                }
            }
        };

        visited[s] = 1;
        dfs(s, 0);
        return res;
    }
};