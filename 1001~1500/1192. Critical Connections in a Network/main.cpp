/**
 * Source: https://rb.gy/4lvay
 * Date: 2023/9/2
 * Skill:
 * Runtime: 708 ms, faster than 22.32% of C++ online submissions
 * Memory Usage: 252.8 MB, less than 5.17% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<unordered_set<int>> adj_set(n);
        vector<int> step(n, -1);
        for (auto edge: connections) {
            adj_set[edge[0]].insert(edge[1]);
            adj_set[edge[1]].insert(edge[0]);
        }
        for (int i = 0; i < n; i++) {
            if (step[i] == -1) {
                step[i] = 0;
                int num = dfs(i, -1, adj_set, step);
            }
        }
        return res;
    }
    int dfs(int cur_pos, int parent, vector<unordered_set<int>>& adj_set, vector<int>& step) {
        int min_num = step[cur_pos];
        for (auto i: adj_set[cur_pos]) {
            if (i == parent)
                continue;
            else if (step[i] == -1) {
                step[i] = step[cur_pos] + 1;
                int min_step = dfs(i, cur_pos, adj_set, step);
                if (min_step > step[cur_pos])
                    res.push_back({cur_pos, i});
                min_num = min(min_num, min_step);
            } else if (step[i] < step[cur_pos]){
                min_num = min(min_num, step[i]);
            }
        }
        return min_num;
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
    vector<vector<int>> nums{{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> res = s.criticalConnections(4, nums);
    for (auto v: res)
        cout << v[0] << " " << v[1] << endl;
}