// Source: https://leetcode.com/problems/maximum-length-of-repeated-subarray/
// Date: 2021/7/10
// Hint: Use dynamic programming. dp[i][j] will be the answer for inputs A[i:], B[j:].

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size(), ans = 0;
        int dp[l1][l2];
        for(int i = 0; i < l1; i++) {
            for(int j = 0; j < l2; j++) {
                if(nums1[i] != nums2[j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])+1;
            }
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