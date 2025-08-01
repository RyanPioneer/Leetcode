/*
 * @lc app=leetcode id=3607 lang=cpp
 *
 * [3607] Power Grid Maintenance
 */

// @lc code=start
class Solution {
   public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> nums(c, -1), running(c, 1);
        vector<vector<int>> graph(c);
        vector<priority_queue<int, vector<int>, greater<int>>> groups;
        for (auto& conn : connections) {
            graph[conn[0] - 1].push_back(conn[1] - 1);
            graph[conn[1] - 1].push_back(conn[0] - 1);
        }

        int id = -1;
        function<void(int)> dfs = [&](int u) {
            for (int v : graph[u]) {
                if (nums[v] == -1) {
                    groups.back().push(v);
                    nums[v] = id;
                    dfs(v);
                }
            }
        };

        for (int i = 0; i < c; i++) {
            if (nums[i] == -1) {
                priority_queue<int, vector<int>, greater<int>> group;
                group.push(i);
                groups.push_back(move(group));
                nums[i] = ++id;
                dfs(i);
            }
        }

        vector<int> res;
        for (auto& q : queries) {
            if (q[0] == 1) {
                if (running[q[1] - 1]) {
                    res.push_back(q[1]);
                    continue;
                }
                while (!groups[nums[q[1] - 1]].empty() &&
                       !running[groups[nums[q[1] - 1]].top()]) {
                    groups[nums[q[1] - 1]].pop();
                }
                if (!groups[nums[q[1] - 1]].empty()) {
                    res.push_back(groups[nums[q[1] - 1]].top() + 1);
                } else {
                    res.push_back(-1);
                }
            } else {
                running[q[1] - 1] = 0;
            }
        }
        return res;
    }
};
// @lc code=end
