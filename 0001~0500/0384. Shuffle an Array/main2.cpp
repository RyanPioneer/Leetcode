/** 
 * Source: https://leetcode.com/problems/shuffle-an-array/
 * Date: 2021/7/20
 * Runtime:  68 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 90.2 MB, less than 89.94% of C++ online submissions
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
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<int> nums_;
    vector<int> toshuffle_;
public:
    Solution(vector<int> nums) {
        nums_ = nums;
        toshuffle_ = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        toshuffle_ = nums_;
        return nums_;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(toshuffle_.begin(), toshuffle_.end());
        return toshuffle_;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
