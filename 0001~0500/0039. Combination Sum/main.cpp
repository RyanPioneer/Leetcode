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
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> vec = {0};
        cal(candidates, target, vec, 0);
        return ans;
    }
    void cal(vector<int>& candidates, int target, vector<int> curVec, int index) {
        if(index == candidates.size())
            return;
        int sum = curVec.back();
        vector<int> nextVec = curVec;
        while(sum + candidates[index] <= target) {
            if(sum + candidates[index] == target) {
                nextVec.pop_back();
                nextVec.push_back(candidates[index]);
                ans.push_back(nextVec);
                break;
            } else {
                nextVec.pop_back();
                nextVec.push_back(candidates[index]);
                nextVec.push_back(sum + candidates[index]);
                cal(candidates, target, nextVec, index+1);
                sum += candidates[index];
            }
        }
        cal(candidates, target, curVec, index+1);
    }

};

int main() {
    vector<int> v1 = {2,3,6,7};
    Solution s;
    vector<vector<int>>sol = s.combinationSum(v1, 7);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();