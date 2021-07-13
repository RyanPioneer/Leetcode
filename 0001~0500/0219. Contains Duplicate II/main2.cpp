/** 
 * Source: https://leetcode.com/problems/contains-duplicate-ii/
 * Date: 2021/7/13
 * Skill: Sliding Window
 * Constraints: 
 *  1 <= nums.length <= 10^5
 *  -10^9 <= nums[i] <= 10^9
 *  0 <= k <= 10^5
 */

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        for(int i = 0 ; i < nums.size() ; i ++) {
            if(record.find(nums[i]) != record.end())
                return true;
            record.insert(nums[i]);
            // 保持record中最多有k个元素
            // 因为在下一次循环中会添加一个新元素,使得总共考虑k+1个元素
            if(record.size() == k + 1)
                record.erase(nums[i - k]);
        }
        return false;
    }
};