/**
 * Source: ibit.ly/nvU7G
 * Date: 2023/9/28
 * Skill:
 * Runtime: 538 ms, faster than 72.58% of C++ online submissions
 * Memory Usage: 197.89 MB, less than 53.55% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 10 ** 4
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
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int> adj_list[n];
        vector<int> visited(n, 0);
        vector<int> dist(n, -1);
        for (auto e: edges) {
            adj_list[e[0] - 1].push_back(e[1] - 1);
            adj_list[e[1] - 1].push_back(e[0] - 1);
        }
        visited[0] = 1;
        dist[0] = 0;
        queue<pairs> q;
        q.push({0, 0});

        while (!q.empty()) {
            auto [cur_time, idx] = q.front(); q.pop();
            if (cur_time / change % 2 == 1)
                cur_time += change - cur_time % change;
            cur_time += time;
            for (auto i: adj_list[idx]) {
                if (visited[i] < 2 && cur_time > dist[i]) {
                    if (i == n - 1 && visited[i] == 1)
                        return cur_time;
                    visited[i]++;
                    dist[i] = cur_time;
                    q.push({cur_time, i});
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{1, 2}};
    int res = s.secondMinimum(arr1, 3, 2);
}