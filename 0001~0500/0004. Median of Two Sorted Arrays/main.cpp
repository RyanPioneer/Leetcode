/** 
 * Source: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * Date: 2022/2/18
 * Skill: Divide and Conquer
 * Runtime:  ms
 * Time complexity: O(log (m+n))
 * Space complexity: 
 * Constraints: 
 *      nums1.length == m
 *      nums2.length == n
 *      0 <= m <= 1000
 *      0 <= n <= 1000
 *      1 <= m + n <= 2000
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();