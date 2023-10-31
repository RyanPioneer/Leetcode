/**
 * Source: t.ly/a-NS3
 * Date: 2023/10/31
 * Skill:
 * Runtime: 57 ms, faster than 62.10% of C++ online submissions
 * Memory Usage: 10.04 MB, less than 46.86% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total = accumulate(begin(nums), end(nums), 0), sz = nums.size();
        int num = total / k, final_state = (1 << sz) - 1;
        if (total % k != 0) return false;
        int dp[1 << 16] = {0};
        function<bool(int, int)> dfs;
        dfs = [&](int cur_state, int cur_sum) {
            if (dp[cur_state] == 1) return true;
            if (dp[cur_state] == -1) return false;
            if (cur_sum > num) return false;
            if (cur_state == final_state) return true;
            if (cur_sum == num) cur_sum = 0;
            for (int i = 0; i < sz; ++i) {
                if (((cur_state >> i) & 1) == 0) {
                    if (dfs(cur_state + (1 << i), cur_sum + nums[i])) {
                        dp[cur_state] = 1;
                        return true;
                    }
                }
            }
            dp[cur_state] = -1;
            return false;
        };
        return dfs(0, 0);
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3,4};
}