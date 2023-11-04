/**
 * Source: t.ly/pLp59
 * Date: 2023/11/4
 * Skill:
 * Runtime: 55 ms, faster than 65.00% of C++ online submissions
 * Memory Usage: 40.67 MB, less than 28.75% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int maxValueAfterReverse(vector<int>& nums) {
        int total = 0, res = 0, mx = INT32_MIN, mi = INT32_MAX, sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            total += abs(nums[i + 1] - nums[i]);
            res = max(res, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]));
            res = max(res, abs(nums[i] - nums[sz - 1]) - abs(nums[i + 1] - nums[i]));
            mx = max(mx, min(nums[i], nums[i + 1]));
            mi = min(mi, max(nums[i], nums[i + 1]));
            res = max(res, (min(nums[i], nums[i + 1]) - mi) * 2);
            res = max(res, (mx - max(nums[i], nums[i + 1])) * 2);
        }
        return total + res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}