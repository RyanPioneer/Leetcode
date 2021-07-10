// Source: https://leetcode.com/problems/longest-increasing-subsequence/
// Date: 2021/7/10
// Dynamic Programming
// O(n log(n))

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int ans[2501] = {0};
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();

    }
};



static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();