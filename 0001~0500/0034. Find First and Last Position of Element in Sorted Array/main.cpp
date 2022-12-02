/** 
 * Source: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 * Date: 2022/7/6
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      0 <= nums.length <= 10^5
 *      -10^9 <= nums[i] <= 10^9
 *      nums is a non-decreasing array.
 *      -10^9 <= target <= 10^9
 *      
 */

#include<iostream>
#include<vector>
#include<string>
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int index = nums.size()/2, lower_bound = 0, upper_bound = nums.size()-1;
        while (1) {
            if (nums[index] == target)
                break;
            else if (nums[index] > target) {
                if (index == lower_bound)
                    return {-1, -1};
                upper_bound = index;
                index = (index + lower_bound)/2;
            } else if (nums[index] < target) {
                if (index == upper_bound)
                    return {-1, -1};
                lower_bound = index;
                index = (index + upper_bound)/2;
            }
        }
        
        int left = (lower_bound+index)/2, mid = index;
        while (left != lower_bound) {
            if (nums[left] != nums[index]) {
                left = (left+mid)/2;
                mid = 
            }
        }
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();