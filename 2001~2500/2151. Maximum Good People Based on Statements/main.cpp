/**
 * Source: t.ly/xzdhd
 * Date: 2023/11/3
 * Skill:
 * Runtime: 41 ms, faster than 90.35% of C++ online submissions
 * Memory Usage: 8.73 MB, less than 38.60% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 16;

class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        const int n = statements.size();
        int res = 0, assume[MX];
        for (int i = 0; i < n; ++i) assume[i] = 2;
        function<int(int)> dfs;
        dfs = [&](int cur) {
            if (cur == n) return 0;
            for (int i = 0; i < n; ++i) {
                if (i == cur) continue;
                if (assume[i] == 2) continue;
                if (assume[cur] == 1 && statements[cur][i] != 2 && statements[cur][i] != assume[i]) {
                    return INT32_MIN;
                }
                if (assume[i] == 1 && statements[i][cur] != 2 && statements[i][cur] != assume[cur]) {
                    return INT32_MIN;
                }
            }
            int num = INT32_MIN;
            assume[cur + 1] = 1;
            int n1 = dfs(cur + 1);
            if (n1 != INT32_MIN) num = n1 + (cur != n - 1);
            assume[cur + 1] = 0;
            n1 = dfs(cur + 1);
            if (n1 != INT32_MIN) num = max(num, n1);
            assume[cur + 1] = 2;
            return num;
        };
        assume[0] = 1;
        int k = dfs(0);
        if (k != INT32_MIN) res = k + 1;
        assume[0] = 0;
        k = dfs(0);
        if (k != INT32_MIN) res = max(res, k);
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    int res = s.maximumGood(arr);
    vector<int> nums{0, 1};
}