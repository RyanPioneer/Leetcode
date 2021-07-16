/** 
 * Source: https://leetcode.com/problems/two-sum/
 * Date: 2021/7/16
 * Skill: Hashmap
 * Runtime: 8 ms, faster than 95.15% of C++ online submissions
 * Memory Usage: 10.9 MB, less than 26.99% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n) 
 * Constraints: 
 *      Only one valid answer exists.
 *      you may not use the same element twice.
 */

#include <vector>
#include <iostream>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> entries;
        for (int i = 0; i < nums.size(); i++) {
            if (entries.count(target - nums[i]))
                return {i, entries[target - nums[i]]};
            else 
                entries[nums[i]] = i;
        }
        return {};
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();