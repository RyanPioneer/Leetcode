/** 
 * Source: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Date: 2021/7/16
 * Skill: Two Points
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.5 MB, less than 74.95% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      2 <= numbers.length <= 3 * 10^4
 *      numbers is sorted in non-decreasing order.
 *      The tests are generated such that there is exactly one solution.
 *      You may not use the same element twice.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 1, right = numbers.size();
        while (1) {
            if (numbers[left-1] + numbers[right-1] == target)
                return {left, right};
            else if (numbers[left-1] + numbers[right-1] > target)
                right--;
            else
                left++;
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