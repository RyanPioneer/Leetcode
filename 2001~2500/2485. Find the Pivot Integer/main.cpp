/** 
 * Source: https://leetcode.com/problems/find-the-pivot-integer/
 * Date: 2022/11/29
 * Skill: 
 * Runtime: 3 ms, faster than 67.63%
 * Memory Usage:  7.4 MB, less than 10.47%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= n <= 1000
 *      It is guaranteed that there will be at most one pivot index for the given input.
 */

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int pivotInteger(int n) {
        vector<int> nums(n,0);
        nums[0] = 1;
        for (int i = 2; i <= n; i++) {
            nums[i-1] = nums[i-2]+i;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i]*2-(i+1) == nums[n-1])
                return i+1;
        }
        return -1;
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();