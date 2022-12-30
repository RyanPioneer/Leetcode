/** 
 * Source: https://leetcode.com/problems/combination-sum-ii/
 * Date: 2022/12/24
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= candidates.length <= 100
 *      Each number in candidates may only be used once in the combination.
 *      The solution set must not contain duplicate combinations.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res; 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
    }
    
    void backTracking(vector<int>& candidates, int target, int index, vector<int>& members) {
        
    }
};

static const auto io_sync_off = []() {
    // * turn off sync
    std::ios::sync_with_stdio(false);
    // * untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();