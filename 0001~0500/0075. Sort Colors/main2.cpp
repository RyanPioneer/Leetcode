/** 
 * Source: https://leetcode.com/problems/sort-colors/
 * Date: 2022/7/12
 * Skill: DNF sort
 * Runtime:  
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *     
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid >= low and mid <= high and mid < n) {
            if(nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1) {
                mid++;
            }
            else if(nums[mid] == 2) {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();