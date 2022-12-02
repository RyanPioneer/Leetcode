/** 
 * Source: https://leetcode.com/problems/find-the-pivot-integer/
 * Date: 2022/11/29
 * Skill: 
 * Runtime: 0 ms, faster than 100.00%
 * Memory Usage:  5.8 MB, less than 76.24%
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
        for (int i = 1; i <= n; i++) {
            if (i*(i+1)-i == n*(n+1)/2)
                return i;
        }
        return -1;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();