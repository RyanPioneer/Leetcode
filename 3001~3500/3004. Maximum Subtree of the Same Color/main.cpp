/**
 * Source: t.ly/AjiPO
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 361 ms, faster than 25.76% of C++ online submissions
 * Memory Usage: 202.67 MB, less than 45.45% of C++ online submissions
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


class Solution {
public:
    int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
        int n = colors.size(), res = 1;
        vector<vector<int>> graph(n);

        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<PII(int, int)> dfs = [&](int cur, int par) {
            int num = 1;

            for (auto &e: graph[cur]) {
                if (e == par) continue;
                auto [nodeNum, color] = dfs(e, cur);
                num += nodeNum;
                if (color != colors[cur]) colors[cur] = -1;
            }

            if (colors[cur] != -1) res = max(res, num);
            return make_pair(num, colors[cur]);
        };

        dfs(0, -1);
        return res;
    }
};