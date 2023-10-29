/**
 * Source: ibit.ly/F_mc7
 * Date: 2023/10/29
 * Skill:
 * Runtime: 109 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 87.02 MB, less than 90.00% of C++ online submissions
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
        ll first_no_take = 0, first_take = k - nums[idx[0]];
        ll second_no_take = 0, second_take = k - nums[idx[1]];
        ll cur_no_take, cur_take;
        for (int i = 2; i < sz; i++) {
            cur_take = k - nums[idx[i]] + min(second_no_take, second_take);
            if (idx[i - 1] == idx[i] - 1 && idx[i - 2] == idx[i] - 2) {
                cur_no_take = min(second_take, first_take);
            } else {
                cur_no_take = min(second_take, second_no_take);
            }
            first_no_take = second_no_take, first_take = second_take;
            second_no_take = cur_no_take, second_take = cur_take;
        }
        return min(cur_no_take, cur_take);
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}