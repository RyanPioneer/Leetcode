/** 
 * Source: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 20 ms, faster than 98.01% of C++ online submissions
 * Memory Usage: 20.7 MB, less than 67.64% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      left and right are non-empty
 *      2 <= nums.length <= 30000
 *      0 <= nums[i] <= 10^6
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& a) {
        int minNum = a[0], maxNum = a[0], index = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] < minNum) {
                index = i;
                minNum = maxNum;
            }
            maxNum = max(a[i],maxNum);
        }
        return index+1;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();