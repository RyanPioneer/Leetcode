/**
 * Source: ibit.ly/4Egog
 * Date: 2023/10/29
 * Skill:
 * Runtime: 625 ms, faster than 55.56% of C++ online submissions
 * Memory Usage: 264.66 MB, less than 11.11% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        const int sz = coins.size();
        vector<vector<int>> dp(sz, vector<int>(13, -1));
        vector<vector<int>> children(sz);
        for (auto e: edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }
        function<int(int, int, int)> dfs;
        dfs = [&](int cur, int par, int div_t) {
            if (div_t >= 13) return 0;
            if (dp[cur][div_t] != -1) return dp[cur][div_t];
            int score = (coins[cur] >> div_t);
            int num1 = (score - k), num2 = score / 2;
            for (int i: children[cur]) {
                if (i == par) continue;
                num1 += dfs(i, cur, div_t);
                num2 += dfs(i, cur, div_t + 1);
            }
            dp[cur][div_t] = max(num1, num2);
            return dp[cur][div_t];
        };
        return dfs(0, -1, 0);
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}