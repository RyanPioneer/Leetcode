/**
 * Source: jpeg.ly/gwL_o
 * Date: 2025/1/15
 * Skill:
 * Ref:
 * Runtime: 1023 ms, faster than 29.19% of C++ online submissions
 * Memory Usage: 353.78 MB, less than 66.42% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
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

#define ll long long


class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1, res = 0;
        vector<vector<int>> graph(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<int(int, int)> dfs = [&](int node, int par) {
            int total = 1, prevNum = -1;
            int check = 1;
            for (auto &next: graph[node]) {
                if (next == par) continue;
                int num = dfs(next, node);
                if (prevNum != -1 && num != prevNum) {
                    check = 0;
                }
                total += num;
                prevNum = num;
            }
            if (check) res++;
            return total;
        };

        dfs(0, -1);
        return res;
    }
};
