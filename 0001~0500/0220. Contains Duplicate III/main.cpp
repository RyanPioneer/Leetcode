/** 
 * Source: https://leetcode.com/problems/contains-duplicate-iii/
 * Date: 2021/7/18
 * Skill: Sliding Window
 * Runtime: 32 ms, faster than 79.89% of C++ online submissions
 * Memory Usage: 18.8 MB, less than 23.11% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      0 <= nums.length <= 2 * 10^4
 * Goal: find two distinct indices i and j in the array 
 *      such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.
 */
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> mySet;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k)
                mySet.erase(nums[i-k-1]);
            auto j = mySet.lower_bound((long)nums[i] - (long)t);    // * Note!!
            if (j != mySet.end() && *j - nums[i] <= t)
                return true;
            mySet.insert((long)nums[i]);
        }
        return false;
    }
};

int main() {
    vector<int> vec = {1,5,9,1,5,9};
    Solution s;
    cout<<s.containsNearbyAlmostDuplicate(vec, 2, 3);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();