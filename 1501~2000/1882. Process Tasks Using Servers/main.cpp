/**
 * Source: tinyurl.com/yk7zqtzb
 * Date: 2023/10/28
 * Skill:
 * Runtime: 351 ms, faster than 89.43% of C++ online submissions
 * Memory Usage: 120.06 MB, less than 91.49% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


typedef pair<int, int> pairs;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        vector<int> res(tasks.size());
        priority_queue<pairs, vector<pairs>, greater<pairs>> busy, free;
        for (int i = 0; i < servers.size(); i++) free.push({servers[i], i});
        int cur_time = 0;
        for (int i = 0; i < tasks.size(); i++) {
            cur_time = max(cur_time, i);
            if (free.empty()) cur_time = busy.top().first;
            while (!busy.empty() && busy.top().first <= cur_time) {
                auto [_, idx] = busy.top();
                busy.pop();
                free.push({servers[idx], idx});
            }
            auto [_, idx] = free.top();
            free.pop();
            res[i] = idx;
            busy.push({cur_time + tasks[i], idx});
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}