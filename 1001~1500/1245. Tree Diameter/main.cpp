/**
 * Source: ibit.ly/RVTGr
 * Date: 2024/6/30
 * Skill:
 * Ref:
 * Runtime: 38 ms, faster than 55.13% of C++ online submissions
 * Memory Usage: 22.64 MB, less than 96.58% of C++ online submissions
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
const int MX = 1e4+10;


class Solution {
public:
    int treeDiameter(vector<vector<int>>& edges) {
        vector<int> graph[MX];
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int res = 0;

        function<int(int, int)> helper = [&](int cur, int par) {
            int d1 = 0, d2 = 0;
            for (auto &e: graph[cur]) {
                if (e == par) continue;
                int d = helper(e, cur);
                if (d > d1) {
                    d2 = d1;
                    d1 = d;
                } else if (d > d2) {
                    d2 = d;
                }
            }
            res = max(res, d1 + d2);
            return d1 + 1;
        };

        helper(0, -1);
        return res;
    }
};