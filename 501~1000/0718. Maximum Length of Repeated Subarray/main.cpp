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
        int dp[1001][1001] = {0};
        dp[0][0] = dp[0][1] = dp[1][0] = 0;
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(nums1[i-1] != nums2[j-1])
                    dp[i][j] = 0;
                else {
                    dp[i][j] = dp[i-1][j-1]+1;
                    ans = (ans>dp[i][j])?ans:dp[i][j];
                }
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