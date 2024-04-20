/**
 * Source: is.gd/OYhLs6
 * Date: 2024/4/20
 * Skill:
 * Ref:
 * Runtime: 269 ms, faster than 41.82% of C++ online submissions
 * Memory Usage: 45.08 MB, less than 70.91% of C++ online submissions
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
const int MX = 1e3+5;


class Solution {
public:
    int maximumProcessableQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size(), dp[MX][MX] = {0}, res = 0;
        for (int num = 1; num <= n; num++) {
            if (num == n) {
                for (int i = 0; i < n; i++) {
                    if (queries[dp[i][i]] <= nums[i]) {
                        res = max(res, dp[i][i] + 1);
                    }
                }
                break;
            }
            for (int left = 0; left <= num; left++) {
                int right = n - (num + 1 - left);
                if (left != 0) {
                    dp[left][right] = dp[left - 1][right];
                    if (queries[dp[left - 1][right]] <= nums[left - 1]) {
                        dp[left][right] = max(dp[left][right], dp[left - 1][right] + 1);
                    }
                }
                if (right != n - 1) {
                    dp[left][right] = max(dp[left][right], dp[left][right + 1]);
                    if (queries[dp[left][right + 1]] <= nums[right + 1]) {
                        dp[left][right] = max(dp[left][right], dp[left][right + 1] + 1);
                    }
                }
                res = max(res, dp[left][right]);
                if (res == n || res == m) return res;
            }
        }
        return res;
    }
};