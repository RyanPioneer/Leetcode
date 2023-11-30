/**
 * Source: is.gd/cGpqDR
 * Date: 2023/11/30
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 98.87% of C++ online submissions
 * Memory Usage: 7.74 MB, less than 93.42% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;
#define SZ(X) ((int)(X).size())
const int MX = 101;


class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        double dp[MX][MX] = {0}, presum[MX] = {0}, res = 0;
        for (int i = 0; i < SZ(nums); i++) presum[i + 1] = presum[i] + nums[i];
        for (int i = 0; i < SZ(nums); i++) {
            dp[i][1] = presum[i + 1] / (i + 1);
            for (int j = 2; j <= min(i + 1, k); j++) {
                dp[i][j] = dp[i - 1][j - 1] + nums[i];
                for (int l = i - 1; l >= j - 2; l--) {
                    dp[i][j] = max(dp[i][j], dp[l][j - 1] + (presum[i + 1] - presum[l + 1]) / (i - l));
                }
            }
        }
        for (int i = 1; i <= k; i++) res = max(res, dp[SZ(nums) - 1][i]);
        return res;
    }
};