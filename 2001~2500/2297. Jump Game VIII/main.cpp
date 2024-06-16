/**
 * Source: t.ly/5-qtz
 * Date: 2024/6/6
 * Skill:
 * Ref:
 * Runtime: 116 ms, faster than 84.95% of C++ online submissions
 * Memory Usage: 99.87 MB, less than 100.00% of C++ online submissions
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
const int MX = 1e5+7;


class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& costs) {
        int n = nums.size();
        ll dp[MX] = {0};
        vector<int> q1(1, 0), q2(1, 0);
        for (int i = 1; i < n; i++) {
            ll a = LLONG_MAX / 2, b = LLONG_MAX / 2;
            while (!q1.empty() && nums[i] >= nums[q1.back()]) {
                a = min(a, dp[q1.back()]);
                q1.pop_back();
            }
            dp[i] = a + costs[i];
            while (!q2.empty() && nums[i] < nums[q2.back()]) {
                b = min(b, dp[q2.back()]);
                q2.pop_back();
            }
            dp[i] = min(dp[i], b + costs[i]);
            q1.push_back(i);
            q2.push_back(i);
        }
        return dp[n-1];
    }
};