// Source: https://leetcode.com/problems/permutations-ii/
// Date: 2021/7/11

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
private:
    vector<vector<int>> res;
    vector<bool> used;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        if(nums.size() == 0)
            return res;
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> p;
        generatePermutation(nums, 0, p);
        return res;
    }
private:
    void generatePermutation(const vector<int>& nums, int index, vector<int> &p) {
        if(index == nums.size()) {
            res.push_back(p);
            return;
        }
        for(int i=0; i<nums.size(); i++)
            if(!used[i]) {
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                    continue;
                p.push_back(nums[i]);
                used[i] = true;
                generatePermutation(nums, index + 1, p);
                p.pop_back();
                used[i] = false;
            }
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();