/**
 * Source: is.gd/qOYE6r
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 725 ms, faster than 44.44% of C++ online submissions
 * Memory Usage: 193.64 MB, less than 55.56% of C++ online submissions
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

const int MX = 1e5+10;


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> adjList(n);
        for (auto &e: edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        int idx = 1;
        int group[MX] = {0}, nums[MX];

        function<void(int)> dfs = [&](int cur) {
            group[cur] = idx;
            for (auto &i: adjList[cur]) {
                if (group[i] == 0) {
                    dfs(i);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (group[i] == 0) {
                dfs(i);
                idx++;
            }
        }

        for (int i = 1; i < idx; i++) nums[i] = (1 << 20) - 1;

        for (auto &e: edges) {
            nums[group[e[0]]] &= e[2];
        }

        vector<int> res;
        for (auto &q: query) {
            if (q[0] == q[1]) {
                res.push_back(0);
            } else if (group[q[0]] != group[q[1]]) {
                res.push_back(-1);
            } else {
                res.push_back(nums[group[q[0]]]);
            }
        }
        return res;
    }
};