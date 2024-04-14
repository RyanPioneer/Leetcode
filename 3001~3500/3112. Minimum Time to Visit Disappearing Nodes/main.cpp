/**
 * Source: is.gd/Axk4n0
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 348 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 167.04 MB, less than 100.00% of C++ online submissions
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
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> res(n, -1);
        vector<vector<PII>> adjList(n);
        for (auto &e: edges) {
            adjList[e[0]].push_back({e[1], e[2]});
            adjList[e[1]].push_back({e[0], e[2]});
        }

        priority_queue<PII, vector<PII>, greater<>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (disappear[node] <= time || res[node] != -1) continue;
            res[node] = time;
            for (auto &e: adjList[node]) {
                if (res[e.first] == -1) pq.push({time + e.second, e.first});
            }
        }
        return res;
    }
};