/** 
 * Source: https://leetcode.com/problems/contains-duplicate-iii/
 * Date: 2021/7/18
 * * Skill: Bucket Sort
 * map vs unordered_map: https://www.geeksforgeeks.org/map-vs-unordered_map-c/
 * Runtime: 36 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 17.3 MB, less than 71.16% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(k)
 * Constraints: 
 *      0 <= nums.length <= 2 * 10^4
 * Goal: find two distinct indices i and j in the array 
 *      such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
 */
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<int, int> buckets;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                int keyToRemove = nums[i-k-1]/((long)t+1);
                if (nums[i-k-1] < 0 && nums[i-k-1]%((long)t+1) != 0)
                    keyToRemove--;
                buckets.erase(keyToRemove);
            }
            int newKey = nums[i]/((long)t+1);
            if (nums[i] < 0 && nums[i]%((long)t+1) != 0)
                newKey--;
            if (buckets.count(newKey))
                return true;
            if (buckets.count(newKey+1)) {
                if ((long)buckets[newKey+1] - (long)nums[i] <= (long)t)
                    return true;
            }
            if (buckets.count(newKey-1)) {
                if ((long)nums[i] - (long)buckets[newKey-1] <= (long)t)
                    return true;
            }
            buckets.insert(make_pair(newKey, nums[i]));
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