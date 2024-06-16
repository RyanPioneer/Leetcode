/**
 * Source: t.ly/rWogj
 * Date: 2024/6/7
 * Skill:
 * Ref:
 * Runtime: 138 ms, faster than 55.67% of C++ online submissions
 * Memory Usage: 21.85 MB, less than 69.07% of C++ online submissions
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


const int MX = 1e3+7;


class Solution {
public:
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int matrix[MX][MX] = {0};
        vector<int> graph[MX];
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<void(int, int)> dfs = [&](int root, int cur) {
            for (auto &e: graph[cur]) {
                if (!matrix[root][e] && e != root) {
                    matrix[root][e] = matrix[root][cur] + 1;
                    dfs(root, e);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            dfs(i, i);
        }

        vector<int> res;
        for (auto &q: query) {
            int d = matrix[q[0]][q[2]], ret = q[0];
            while (true) {
                if (matrix[q[0]][q[2]] < d) {
                    d = matrix[q[0]][q[2]];
                    ret = q[0];
                }
                if (q[0] == q[1]) break;
                for (auto &e: graph[q[0]]) {
                    if (matrix[q[0]][q[1]] > matrix[e][q[1]]) {
                        q[0] = e;
                        break;
                    }
                }
            }
            res.push_back(ret);
        }
        return res;
    }
};