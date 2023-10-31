/**
 * Source: ibit.ly/VBSP2
 * Date: 2023/10/31
 * Skill: 位運算尋找子集: t.ly/NCdwr
 * Runtime: 410 ms, faster than 14.46% of C++ online submissions
 * Memory Usage: 10.94 MB, less than 33.13% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 13;

class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int sz1 = cost.size(), sz2 = cost[0].size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(1 << sz2, INT_MAX / 2));
        int min_cost[MX], cost_for_subset[MX][1 << MX] = {0};
        for (int i = 0; i < sz1; i++) {
            min_cost[i] = cost[i][0];
            for (int j = 1; j < sz2; j++) {
                min_cost[i] = min(min_cost[i], cost[i][j]);
            }
        }
        for (int i = 0; i < sz1; i++) {
            for (int state = 1; state < (1 << sz2); state++) {
                int sum = 0;
                for (int j = 0; j < sz2; j++) {
                    if (((state >> j) & 1) != 0) sum += cost[i][j];
                }
                cost_for_subset[i][state] = sum;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i < sz1; i++) {
            dp[i + 1][0] = INT32_MAX / 2;
            for (int state = (1 << sz2) - 1; state > 0; state--) {
                dp[i + 1][state] = dp[i][state] + min_cost[i];
                for (int substate = state; substate > 0; substate = ((substate - 1) & state)) {
                    dp[i + 1][state] = min(dp[i + 1][state], dp[i][state - substate] + cost_for_subset[i][substate]);
                }
            }
        }
        return dp[sz1][(1 << sz2) - 1];
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}