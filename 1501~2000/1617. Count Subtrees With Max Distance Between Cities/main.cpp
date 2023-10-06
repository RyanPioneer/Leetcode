/**
 * Source: ibit.ly/u19fl
 * Date: 2023/10/6
 * Skill: find diameter
 * Runtime: 259 ms, faster than 23.24% of C++ online submissions
 * Memory Usage: 275.68 MB, less than 15.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 15
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
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int> res(n, 0), adj_list[15];
        for (auto e: edges) {
            adj_list[e[0] - 1].push_back(e[1] - 1);
            adj_list[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> picked_nodes(n, 0), dist(n, -1);
        for (int state = 1; state < (1 << n); state++) {
            int start, cnt = 0;
            for (int j = 0; j < n; j++) {
                dist[j] = -1;
                if (((state>>j)&1)==1) {
                    picked_nodes[j] = 1;
                    start = j;
                    cnt++;
                }
                else
                    picked_nodes[j] = 0;
            }
            int d1 = bfs(start, n, picked_nodes, adj_list, dist);
            int num = 0;
            for (int i = 0; i < n; i++) {
                if (dist[i] != -1)
                    num++;
                dist[i] = -1;
            }
            if (num != cnt)
                continue;
            int d2 = bfs(d1, n, picked_nodes, adj_list, dist);
            res[dist[d2]]++;
        }
        res.erase(begin(res));
        return res;
    }
    int bfs(int start, int n, vector<int>& picked_nodes, vector<int> adj_list[15], vector<int>& dist) {
        dist[start] = 0;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto i: adj_list[cur])
                if (picked_nodes[i] == 1 && dist[i] == -1) {
                    dist[i] = dist[cur] + 1;
                    q.push(i);
                    start = i;
                }
        }
        return start;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
    vector<int> res = s.countSubgraphsForEachDiameter(4, arr);
}