/**
 * Source: jpeg.ly/QgtPo
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 142 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 49.21 MB, less than 71.43% of C++ online submissions
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


class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, INT32_MAX / 2));
        for (auto &i: roads) {
            adj[i[0]][i[1]] = min(i[2], adj[i[0]][i[1]]);
            adj[i[1]][i[0]] = min(i[2], adj[i[0]][i[1]]);
        }
        int res = 1, total = (1 << n);
        for (int mask = 1; mask < total; ++mask) {
            if (getMaxDistance(mask, n, adj) <= maxDistance) {
                res++;
            }
        }
        return res;
    }
    int getMaxDistance(int mask, int n, vector<vector<int>>& adj) {
        vector<vector<int>> dis = adj;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0) continue;
                for (int k = 0; k < n; k++) {
                    if ((mask & (1 << k)) == 0) continue;
                    if (j != k) dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }
        int max_dis = 0;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (int j = 0; j < n; j++) {
                if (i == j || (mask & (1 << j)) == 0) continue;
                max_dis = max(max_dis, dis[i][j]);
            }
        }
        return max_dis;
    }
};