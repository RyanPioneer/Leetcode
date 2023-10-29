/**
 * Source: ibit.ly/F_mc7
 * Date: 2023/10/29
 * Skill:
 * Runtime: 209 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 126.28 MB, less than 20.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        vector<int> idx;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < k) idx.push_back(i);
        }
        int sz = idx.size();
        if (sz <= 2) return 0;
        vector<vector<ll>> dp(sz, vector<ll>(2, 0));
        dp[0][0] = 0, dp[0][1] = k - nums[idx[0]];
        dp[1][0] = 0, dp[1][1] = k - nums[idx[1]];
        for (int i = 2; i < sz; i++) {
            dp[i][1] = k - nums[idx[i]] + min(dp[i - 1][0], dp[i - 1][1]);
            if (idx[i - 1] == idx[i] - 1 && idx[i - 2] == idx[i] - 2) {
                dp[i][0] = min(dp[i - 1][1], dp[i - 2][1]);
            } else {
                dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
            }
        }
        return min(dp[sz - 1][0], dp[sz - 1][1]);
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}