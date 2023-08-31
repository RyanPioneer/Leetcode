/**
 * Source: https://rb.gy/tkyc4
 * Date: 2023/8/31
 * Skill:
 * Runtime: 231 ms, faster than 47.52% of C++ online submissions
 * Memory Usage: 153.02 MB, less than 6.64% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 50
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<set<int>> adj_set(n);
        for (auto i: edges) {
            adj_set[i[0]].insert(i[1]);
            adj_set[i[1]].insert(i[0]);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
            if (visited[i] == false && dfs(i, adj_set, visited))
                res++;
        return res;
    }
    bool dfs(int start, vector<set<int>>& adj_set, vector<bool>& visited) {
        int edge_num = 0, node_num = 1;
        visited[start] = true;
        queue<int> q;
        q.push(start);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto i: adj_set[cur]) {
                if (!visited[i]) {
                    visited[i] = true;
                    node_num++;
                    q.push(i);
                }
                edge_num++;
            }
        }
        return edge_num == node_num * (node_num - 1);
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> arr{3,2,2,4,3};
    int target = 3;

    cout << target << endl;
}