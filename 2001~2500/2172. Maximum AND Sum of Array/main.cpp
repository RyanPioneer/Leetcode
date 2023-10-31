/**
 * Source: t.ly/nBSAD
 * Date: 2023/10/31
 * Skill:
 * Runtime: 6 ms, faster than 97.98% of C++ online submissions
 * Memory Usage: 8.72 MB, less than 97.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 10;
const int MX_POW = 59049;


class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int sz = nums.size(), res = 0;
        int max_state = pow(3, numSlots), pow3[MX] = {1};
        for (int i = 1; i < MX; i++) pow3[i] = pow3[i - 1] * 3;
        int dp[MX_POW] = {0};
        for (int i = 1; i < max_state; i++) {
            int num = 0, state = i;
            while (state > 0) {
                num += state % 3;
                state /= 3;
            }
            if (num > sz) continue;
            state = i;
            for (int j = 0; j < numSlots && state > 0; j++) {
                if (state % 3 > 0) {
                    dp[i] = max(dp[i], dp[i - pow3[j]] + (nums[num - 1] & (j + 1)));
                }
                state /= 3;
            }
            if (num == sz) res = max(res, dp[i]);
        }
        return res;
    }
};


int main() {
    Solution s;
}