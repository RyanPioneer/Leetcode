/**
 * Source: is.gd/Dr4nmN
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 423 ms, faster than 39.29% of C++ online submissions
 * Memory Usage: 83.41 MB, less than 85.71% of C++ online submissions
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
typedef array<int, 3> AI3;
const int MX = 501;


class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& Edges, int s, int d, int k) {
        vector<PII> edges[MX];

        for (auto &e: Edges) {
            edges[e[0]].push_back({e[1], e[2]});
            edges[e[1]].push_back({e[0], e[2]});
        }

        int dp[MX][MX];

        fill(dp[0], dp[MX - 1] + MX, INT32_MAX / 2);

        priority_queue<AI3, vector<AI3>, greater<>> pq;

        pq.push({0, s, 0});
        dp[s][0] = 0;
        while (!pq.empty()) {
            auto [dis, node, num] = pq.top();
            pq.pop();
            for (auto &e: edges[node]) {
                if (num < k && dis < dp[e.first][num + 1]) {
                    pq.push({dis, e.first, num + 1});
                    dp[e.first][num + 1] = dis;
                }
                if (dis + e.second < dp[e.first][num]) {
                    pq.push({dis + e.second, e.first, num});
                    dp[e.first][num] = dis + e.second;
                }
            }
        }

        return *min_element(dp[d], dp[d] + MX);
    }
};