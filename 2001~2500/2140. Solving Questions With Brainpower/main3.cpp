/**
 * Source: https://rb.gy/s17u8
 * Date: 2023/9/18
 * Skill:
 * Runtime: 351 ms, faster than 21.04% of C++ online submissions
 * Memory Usage: 141.91 MB, less than 6.89% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int sz = questions.size();
        vector<vector<ll>> dp(sz, vector<ll>(2));
        vector<ll> diff(sz);
        dp[0][1] = questions[0][0];
        if (questions[0][1] + 1 < sz)
            diff[questions[0][1] + 1] = dp[0][1];
        ll base = 0;
        for (int i = 1; i < sz; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            base = max(base, diff[i]);
            dp[i][1] = base + questions[i][0];
            if (i + questions[i][1] + 1 < sz)
                diff[i + questions[i][1] + 1] = max(diff[i + questions[i][1] + 1], dp[i][1]);
        }
        return max(dp[sz - 1][0], dp[sz - 1][1]);
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr{{0, 1, 0, 0, 0},
                            {0, 1, 0, 1, 0},
                            {0, 0, 0, 1, 0}};
    map<int, ll> nums;
    nums[2] = 2;
    nums[3] = 2;
    auto it = nums.upper_bound(0);
    cout << (it == begin(nums)) << endl;
}