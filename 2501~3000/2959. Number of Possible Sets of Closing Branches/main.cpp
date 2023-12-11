/**
 * Source: jpeg.ly/QgtPo
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 187 ms, faster than 57.14% of C++ online submissions
 * Memory Usage: 58.02 MB, less than 57.14% of C++ online submissions
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


const int MX = 101;


class Solution {
    int res = 0;
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n, vector<int>(n, INT32_MAX / 2));
        for (auto &i: roads) {
            adj[i[0]][i[1]] = min(i[2], adj[i[0]][i[1]]);
            adj[i[1]][i[0]] = min(i[2], adj[i[0]][i[1]]);
        }
        vector<int> company(n, 0);
        dfs(company, n, 0, maxDistance, adj);
        return res;
    }
    void dfs(vector<int> &company, int n, int idx, int maxDistance, vector<vector<int>>& adj) {
        if (idx == n) {
            vector<vector<int>> dis = adj;
            for (int i = 0; i < n; i++) {
                if (company[i] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (company[j] == 0) continue;
                    for (int k = 0; k < n; k++) {
                        if (company[k] == 0) continue;
                        if (j != k) dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (company[i] == 0) continue;
                for (int j = 0; j < n; j++) {
                    if (i == j || company[j] == 0) continue;
                    if (dis[i][j] > maxDistance) return;
                }
            }
            res++;
            return;
        }
        dfs(company, n, idx + 1, maxDistance, adj);
        company[idx] = 1;
        dfs(company, n, idx + 1, maxDistance, adj);
        company[idx] = 0;
    }
};