/**
 * Source: ibit.ly/4Ni-5
 * Date: 2024/6/9
 * Skill:
 * Ref:
 * Runtime: 100 ms, faster than 14.29% of C++ online submissions
 * Memory Usage: 34.62 MB, less than 28.57% of C++ online submissions
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
const int MX = 5e3+10;


class Solution {
public:
    int maximumLength(vector<int>& nums, int K) {
        int dp[MX][51] = {0}, dp2[MX] = {0}, mx = 1;
        dp[0][0] = dp2[0] = 1;
        unordered_map<int, int> prev;
        prev[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int k = min(i, K); k > 0; k--) {
                if (nums[i] == nums[i-1]) {
                    dp[i][k] = dp[i-1][k] + 1;
                } else {
                    if (prev.find(nums[i]) != prev.end()) {
                        dp[i][k] = dp[prev[nums[i]]][k] + 1;
                    }
                    dp[i][k] = max(dp[i][k], dp2[k-1] + 1);
                }
                mx = max(mx, dp[i][k]);
                dp2[k] = max(dp2[k], dp[i][k]);
            }
            if (nums[i] == nums[i-1]) {
                dp[i][0] = dp[i-1][0]+1;
            } else if (prev.find(nums[i]) != prev.end()) {
                dp[i][0] = dp[prev[nums[i]]][0] + 1;
            } else {
                dp[i][0] = 1;
            }
            mx = max(mx, dp[i][0]);
            dp2[0] = max(dp2[0], dp[i][0]);
            prev[nums[i]] = i;
        }
        return mx;
    }
};