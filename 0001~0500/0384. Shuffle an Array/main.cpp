/** 
 * Source: https://leetcode.com/problems/shuffle-an-array/
 * Date: 2021/7/20
 * * Skill: Fisher-Yates Algorithm
 * Reference: https://gaohaoyang.github.io/2016/10/16/shuffle-algorithm/
 * Runtime: 88 ms, faster than 91.84% of C++ online submissions
 * Memory Usage: 90.3 MB, less than 26.55% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 200
 *      All the elements of nums are unique.
 *      At most 5 * 10^4 calls in total will be made to reset and shuffle.
 */

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        _nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return _nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans = _nums;
        int sz = ans.size();
        for (int i = 0; i < sz-1; i++) {
            //* rand(): Returns a pseudo-random integral number in the range between 0 and RAND_MAX.
            int index = i + rand() % (sz-i); 
            swap(ans[i], ans[index]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();