// Source: https://leetcode.com/problems/permutations/
// Date: 2021/7/11

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        permutation(nums,0);
        return ans;
    }

    void permutation(vector<int>& nums, int index) {
        int len = nums.size();
        if(index == len-1) {
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<len; i++) {
            swap(nums[index], nums[i]);
            permutation(nums, index+1);
            swap(nums[index], nums[i]); //  remember to swap back
        }
    }

    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();