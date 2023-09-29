/**
 * Source: ibit.ly/LEjHW
 * Date: 2023/9/29
 * Skill:
 * Runtime: 206 ms, faster than 94.90% of C++ online submissions
 * Memory Usage: 46.90 MB, less than 54.08% of C++ online submissions
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<int> adj_list[401];
        int adj_mat[401][401] = {0};
        int degree[401] = {0};
        for (auto e: edges) {
            int a = min(e[0], e[1]), b = max(e[0], e[1]);
            adj_list[a].push_back(b);
            degree[e[0]]++;
            degree[e[1]]++;
            adj_mat[e[0]][e[1]] = 1;
            adj_mat[e[1]][e[0]] = 1;
        }
        int res = INT32_MAX;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < adj_list[i].size(); j++) {
                for (int k = j + 1; k < adj_list[i].size(); k++) {
                    int n1 = adj_list[i][j], n2 = adj_list[i][k];
                    if (adj_mat[n1][n2]) {
                        res = min(res, degree[i] + degree[n1] + degree[n2] - 6);
                    }
                }
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}