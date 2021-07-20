/** 
 * Source: https://leetcode.com/problems/first-bad-version/
 * Date: 2021/7/20
 * Skill: Binary Search
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 5.8 MB, less than 64.70% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= bad <= n <= 2^31 - 1
 */

#include<iostream>
#include<vector>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        while (left < n) {
            if (isBadVersion(left + (n - left)/2))
                n = left + (n - left)/2;
            else
                left += (n - left)/2 + 1;
        }
        return n;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();