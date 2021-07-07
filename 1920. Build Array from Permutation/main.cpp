//https://leetcode.com/contest/weekly-contest-248/problems/build-array-from-permutation/

#include<vector>
using namespace std;

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int>ans(nums.size());
        int index = 0;
        for (auto i:nums) {
            ans[index++] = nums[i];
        }
        return ans;
    }
};