/**
 * Source: jpeg.ly/7yQPw
 * Date: 2025/1/19
 * Skill:
 * Ref: jpeg.ly/XCCB6
 * Runtime: 218 ms, faster than 91.25% of C++ online submissions
 * Memory Usage: 82.54 MB, less than 69.22% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= nums.length <= 10 ** 4
 *      1 <= nums[i] <= 300
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
#define ll long long
const int MX = 1e5+10;


class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end()), res = 0;
        int diff = mx - *min_element(nums.begin(), nums.end());
        vector<vector<int>> dp(mx+1, vector<int>(diff+1, 0));

        for (auto &i: nums) {
            int fx = 1;
            for (int j = diff; j >= 0; j--) {
                if (i + j <= mx) {
                    fx = max(fx, dp[i+j][j]+1);
                }
                if (i - j >= 0) {
                    fx = max(fx, dp[i-j][j]+1);
                }
                dp[i][j] = fx;
                res = max(res, fx);
            }
        }
        return res;
    }
};
