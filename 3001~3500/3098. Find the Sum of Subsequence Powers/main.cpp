/**
 * Source: is.gd/geE5Xz
 * Date: 2024/4/16
 * Skill:
 * Ref:
 * Runtime: 305 ms, faster than 80.43% of C++ online submissions
 * Memory Usage: 20.91 MB, less than 98.24% of C++ online submissions
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
#define ll long long

const int MOD = 1e9+7, MX = 55;


class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        ll res = 0, dp[MX][MX];
        int n = nums.size();

        sort(begin(nums), end(nums));

        function<void(int, int)> helper = [&](int left, int right) {
            int d = nums[right] - nums[left];
            ll num = 0;

            fill(dp[0], dp[MX - 1] + MX, 0);
            for (int i = 0; i <= left; i++) dp[i][1] = 1;
            for (int i = n - 1; i >= right; i--) dp[i][1] = 1;
            for (int i = 2; i < k; i++) {
                for (int j = 0; j <= left; j++) {
                    for (int k = 0; k < j; k++) {
                        if (nums[j] - nums[k] > d) {
                            dp[j][i] += dp[k][i - 1];
                        }
                    }
                }
                for (int j = right; j < n; j++) {
                    for (int k = j + 1; k < n; k++) {
                        if (nums[k] - nums[j] >= d) {
                            dp[j][i] += dp[k][i - 1];
                        }
                    }
                }
            }
            for (int i = 1; i < k; i++) {
                num = (num + dp[left][i] * dp[right][k - i]) % MOD;
            }
            res = (res + num * d) % MOD;
        };

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                helper(i, j);
            }
        }
        return res;
    }
};