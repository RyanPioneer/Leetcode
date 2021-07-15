/** 
 * Source: https://leetcode.com/problems/move-zeroes/
 * Date: 2021/7/15
 * Runtime: 4 ms
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 10^4
 *      -2^31 <= nums[i] <= 2^31 - 1
 *      you must do this in-place without making a copy of the array.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0) 
                swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
};