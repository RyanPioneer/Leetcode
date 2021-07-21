/** 
 * Source: https://leetcode.com/problems/arithmetic-slices/
 * Date: 2021/7/21
 * Skill: 
 * Runtime: 4 ms, faster than 62.35% of C++ online submissions
 * Memory Usage: 7.3 MB, less than 54.92% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      consists of at least three contiguous elements
 *      1 <= nums.length <= 5000
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        for (auto i = 2, j = 1; i < A.size(); ++i) {
            if (A[i] - A[i - 1] != A[j] - A[j - 1])
                j = i;
            res += i - j;
        }
        return res;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();