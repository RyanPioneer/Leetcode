/**
 * Source: https://rb.gy/4iwm7
 * Date: 2023/9/17
 * Skill:
 * Runtime: 702 ms, faster than 12.50% of C++ online submissions
 * Memory Usage: 303.35 MB, less than 12.50% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int> res(n, -1);
        vector<unordered_set<int> > out_edge_set(n), in_edge_set(n);
        for (auto e: edges) {
            out_edge_set[e[0]].insert(e[1]);
            in_edge_set[e[1]].insert(e[0]);
        }
        int cnt = 0;
        vector<bool> visited(n, false);
        visited[0] = true;
        deque<int> q;
        q.push_back(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            for (auto i: out_edge_set[cur]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push_back(i);
                }
            }
            for (auto i: in_edge_set[cur]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push_back(i);
                    cnt++;
                }
            }
        }
        res[0] = cnt;
        q.push_back(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            for (auto i: out_edge_set[cur]) {
                if (res[i] == -1) {
                    res[i] = res[cur] + 1;
                    q.push_back(i);
                }
            }
            for (auto i: in_edge_set[cur]) {
                if (res[i] == -1) {
                    res[i] = res[cur] - 1;
                    q.push_back(i);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}