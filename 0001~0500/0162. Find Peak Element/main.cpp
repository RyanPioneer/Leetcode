/** 
 * Source: https://leetcode.com/problems/find-peak-element/
 * Date: 2021/7/13
 * Skill: Binary Search
 * Constraints:
 *  1 <= nums.length <= 1000
 *  nums[i] != nums[i + 1] for all valid i.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int right = nums.size()-1, left = 0;
        while(left < right) {
            int index = (left+right)/2;
            if(nums[index] > nums[index+1]) {
                right = index;
            } else 
                left = index+1;
        }
        return left;
    }
};

int main() {
    vector<int> nums = {2,1};
    Solution s;
    cout<<s.findPeakElement(nums);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();