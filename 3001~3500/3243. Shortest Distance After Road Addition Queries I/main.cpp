/**
 * Source: jpeg.ly/Ims8a
 * Date: 2025/1/16
 * Skill:
 * Ref:
 * Runtime: 82 ms, faster than 61.04% of C++ online submissions
 * Memory Usage: 110.85 MB, less than 54.54% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      3 <= n <= 500
 *      1 <= queries.length <= 500
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


const int MX = 500;


class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> graph[MX];
        bool visited[MX];
        for (int i = 0; i < n-1; i++) {
            graph[i].push_back(i+1);
        }

        vector<int> res;

        for (auto &q: queries) {
            fill(visited, visited+n, false);
            visited[0] = true;
            graph[q[0]].push_back(q[1]);
            queue<int> que;
            que.push(0);
            int dis = 0;
            bool found = false;
            while (!que.empty() && !found) {
                int sz = que.size();
                while (sz-- && !found) {
                    int cur = que.front();
                    que.pop();
                    for (auto &i: graph[cur]) {
                        if (visited[i]) continue;
                        if (i == n-1) {
                            res.push_back(dis+1);
                            found = true;
                            break;
                        }
                        visited[i] = true;
                        que.push(i);
                    }
                }
                dis++;
            }
        }

        return res;
    }
};
