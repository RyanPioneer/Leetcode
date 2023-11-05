/**
 * Source: t.ly/DLk9-
 * Date: 2023/11/5
 * Skill:
 * Runtime: 299 ms, faster than 54.55% of C++ online submissions
 * Memory Usage: 160.70 MB, less than 9.09% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

class Solution {
public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<vector<int>> neighbors(n);
        ll total = accumulate(begin(values), end(values), 0ll);
        for (auto &e: edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        function<void(int, int)> dfs;
        dfs = [&](int cur, int par) {
            if (neighbors[cur].size() == 1 && cur != 0) return;
            int num = 0;
            for (auto &i: neighbors[cur]) {
                if (i == par) continue;
                dfs(i, cur);
                num += values[i];
                if (num > values[cur]) break;
            }
            values[cur] = min(values[cur], num);
            return;
        };
        dfs(0, -1);
        return total - values[0];
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}