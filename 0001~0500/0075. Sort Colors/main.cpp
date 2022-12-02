/** 
 * Source: https://leetcode.com/problems/sort-colors/
 * Date: 2022/7/12
 * Skill: 
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
        int num0 = 0, num1 = 0, num2 = 0, index = 0;
        for (auto i:nums) {
            if (i == 0)
                num0++;
            else if (i == 1)
                num1++;
            else
                num2++;
        }
        while (num0--)
            nums[index++] = 0;
        while (num1--)
            nums[index++] = 1;
        while (num2--)
            nums[index++] = 2;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();