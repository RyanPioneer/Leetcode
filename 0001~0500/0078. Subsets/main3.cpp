/** 
 * Source: https://leetcode.com/problems/subsets/
 * Ref: https://leetcode.com/problems/subsets/discuss/27278/C%2B%2B-RecursiveIterativeBit-Manipulation
 * Date: 2022/7/12
 * Skill: Bit Manipulation
 * Runtime:  
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 10
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Bit Manipulation
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int num = pow(2, nums.size()), sz = nums.size();
        for (int i = 0; i < num; i++) {
            vector<int> vec;
            for (int j = 0; j < sz; j++) {
                if (i & 1<<j)
                    vec.push_back(nums[j]);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();