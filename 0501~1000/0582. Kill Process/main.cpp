/**
 * Source: t.ly/hfDV5
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 117 ms, faster than 23.15% of C++ online submissions
 * Memory Usage: 57.89 MB, less than 100.00% of C++ online submissions
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
const int MX = 5e4+10;


class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res, graph[MX];
        for (int i = 0; i < pid.size(); i++) {
            graph[ppid[i]].push_back(pid[i]);
        }

        function<void(int, bool)> dfs = [&](int cur, bool valid) {
            if (valid) res.push_back(cur);
            for (auto &i: graph[cur]) {
                dfs(i, valid || i == kill);
            }
        };

        dfs(0, false);
        return res;
    }
};