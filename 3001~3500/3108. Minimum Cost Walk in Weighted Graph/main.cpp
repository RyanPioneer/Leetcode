/**
 * Source: is.gd/qOYE6r
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 693 ms, faster than 18.29% of C++ online submissions
 * Memory Usage: 177.87 MB, less than 36.95% of C++ online submissions
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

const int MX = 1e5+10;


class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<PII>> adjList(n);
        for (auto &e: edges) {
            adjList[e[0]].emplace_back(e[1], e[2]);
            adjList[e[1]].emplace_back(e[0], e[2]);
        }

        int idx = 1;
        int group[MX] = {0}, nums[MX];

        function<int(int)> dfs = [&](int cur) {
            group[cur] = idx;
            int num = -1;
            for (auto &i: adjList[cur]) {
                num &= i.second;
                if (group[i.first] == 0) {
                    num &= dfs(i.first);
                }
            }
            return num;
        };

        for (int i = 0; i < n; i++) {
            if (group[i] == 0) {
                nums[idx] = dfs(i);
                idx++;
            }
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