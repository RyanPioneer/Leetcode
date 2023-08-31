/**
 * Source: https://rb.gy/cddhk
 * Date: 2023/8/31
 * Skill:
 * Runtime: 24 ms, faster than 47.60% of C++ online submissions
 * Memory Usage: 17.34 MB, less than 13.97% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;


class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<set<int>> adj_set(n + 1);
        vector<float> res(n + 1, -1);
        for (auto edge: edges) {
            adj_set[edge[0]].insert(edge[1]);
            adj_set[edge[1]].insert(edge[0]);
        }
        queue<int> q;
        res[1] = 1;
        int time = -1;
        q.push(1);
        while (!q.empty()) {
            int sz = q.size();
            time++;
            if (time >= t)
                break;
            for (int k = 0; k < sz; k++) {
                int cur = q.front();
                q.pop();
                if (adj_set[cur].size() == 0)
                    continue;
                for (auto i: adj_set[cur]) {
                    adj_set[i].erase(cur);
                    q.push(i);
                    res[i] = res[cur] / (float)adj_set[cur].size();
                }
                res[cur] = 0;
            }
        }
        return res[target] >= 0 ? res[target] : 0;
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
    string ss = "t";

}