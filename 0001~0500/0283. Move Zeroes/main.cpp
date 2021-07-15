/** 
 * Source: https://leetcode.com/problems/move-zeroes/
 * Date: 2021/7/15
 * Runtime:  4 ms
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
        int num = 0;
        for (int i = 0; i < nums.size()-num; i++) {
            while (i+num < nums.size() && nums[i+num] == 0) 
                num++;
            if (i+num < nums.size())
                nums[i] = nums[i+num];
        }
        while (num>0)
            nums[nums.size()-(num--)] = 0;
    }
};

int main() {
    Solution s;
    vector v1 = {0,1,0,3,12};
    s.moveZeroes(v1);
    for(auto i:v1)
        cout<<i<<' ';
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();