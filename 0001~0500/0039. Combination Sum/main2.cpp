/** 
 * Source: https://leetcode.com/problems/combination-sum/
 * Date: 2021/7/13
 * Skill: Backtracking
 * Constraints:
 *  1 <= candidates.length <= 30
 *  1 <= candidates[i] <= 200
 *  All elements of candidates are distinct.
 *  1 <= target <= 500
 *  The same number may be chosen from candidates an unlimited number of times.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur_res;
        solve(candidates, 0, target, cur_res, res);
        return res;
    }
private:
    void solve(const vector<int> &candidates, int index, int target,
            vector<int>& cur_res, vector<vector<int>>& res) {
        if(target == 0) {
            res.push_back(cur_res);
            return;
        }
        for(int i = index ; i < candidates.size() ; i ++)
            if(target >= candidates[i]) {
                cur_res.push_back(candidates[i]);
                solve(candidates, i, target - candidates[i], cur_res, res);
                cur_res.pop_back();
            }
        return;
    }
};