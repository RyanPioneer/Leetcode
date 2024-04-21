/**
 * Source: t.ly/fM9lh
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 38 ms, faster than 95.76% of C++ online submissions
 * Memory Usage: 30.23 MB, less than 68.90% of C++ online submissions
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


const int MX = 4e4+10;


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1, 0), visited(n + 1, 0);

        for (auto &i: relations) {
            degree[i[1]]++;
            graph[i[0]].emplace_back(i[1]);
        }

        int time = 0;
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            time++;
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                visited[cur] = 1;
                q.pop();
                for (auto &e: graph[cur]) {
                    degree[e]--;
                    if (degree[e] == 0) {
                        q.push(e);
                    }
                }
            }
        }

        return accumulate(begin(visited), end(visited), 0) == n ? time : -1;
    }
};