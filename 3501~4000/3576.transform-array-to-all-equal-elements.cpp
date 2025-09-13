/*
 * @lc app=leetcode id=3576 lang=cpp
 *
 * [3576] Transform Array to All Equal Elements
 */

// @lc code=start
class Solution {
   public:
    bool canMakeEqual(vector<int>& nums, int K) {
        function<bool(vector<int>, int)> check = [&](vector<int> arr, int k) {
            int time = 0, sz = arr.size();
            for (int i = 0; i < sz - 1; i++) {
                if (arr[i] != k) {
                    time++;
                    arr[i + 1] *= -1;
                }
            }
            return time <= K && arr[sz - 1] == k;
        };
        return check(nums, 1) || check(nums, -1);
    }
};
// @lc code=end
