/** 
 * Source: https://leetcode.com/problems/single-number/
 * Date: 2021/7/15
 * Skill: known that A XOR A = 0 and the XOR operator is commutative,
 * Runtime: 8 ms
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      1. 1 <= nums.length <= 3 * 10^4
 *      2. -3 * 10^4 <= nums[i] <= 3 * 10^4
 *      3. Each element in the array appears twice except 
 *      for one element which appears only once.
 *      4. You must implement a solution with a linear runtime 
 *      complexity and use only constant extra space.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums)
            ans ^= i;
        return ans;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();