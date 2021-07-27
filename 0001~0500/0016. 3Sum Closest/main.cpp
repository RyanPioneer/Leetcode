/** 
 * Source: https://leetcode.com/problems/3sum-closest/
 * Date: 2021/7/27
 * Skill: Two Pointers
 * Runtime: 8 ms, faster than 82.85% of C++ online submissions 
 * Memory Usage: 10 MB, less than 11.39% of C++ online submissions
 * Time complexity: O(n^2)
 * Space complexity: 
 * Constraints: 
 *      3 <= nums.length <= 10^3
 *      -10^3 <= nums[i] <= 10^3
 *      -10^4 <= target <= 10^4
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT32_MAX, sz = nums.size();
        for (int i = 0; i < sz-2 && diff != 0; i++) {
            int hi = sz-1, lo = i+1;
            while (hi > lo && diff != 0) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(sum - target) < abs(diff)) diff = sum - target;
                if (sum > target) hi--;
                else if (sum < target) lo++;
            }
        }
        return target + diff;
    }
};

int main () {
    vector<int> nums = {1,2,5,10,11};
    Solution s;
    cout<<s.threeSumClosest(nums, 12);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();