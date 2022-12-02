/** 
 * Source: https://leetcode.com/problems/subsets/
 * Date: 2022/7/12
 * Skill: Iterative
 * Runtime:  
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 10
 */

#include<iostream>
#include<vector>
using namespace std;

// Iterative Solution
// Time complexity : O(N*(2^N))
// Space complexity : O(N*(2^N))
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        ans.push_back({});
        
        for(int i=0; i<n; i++)
        {
            int sz = ans.size();
            for(int j=0; j<sz; j++)
            {
                vector<int> temp = ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
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