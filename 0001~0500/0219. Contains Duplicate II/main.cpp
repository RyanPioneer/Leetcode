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
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int>myMap;
        for(int i=0; i<nums.size(); i++) {
            if(!myMap.count(nums[i]))
                myMap[nums[i]] = i;
            else {
                if(i - myMap[nums[i]] <= k)
                    return true;
                else
                    myMap[nums[i]] = i;
            }
        }
        return false;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();