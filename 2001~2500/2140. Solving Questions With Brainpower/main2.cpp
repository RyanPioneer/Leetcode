/**
 * Source: https://rb.gy/s17u8
 * Date: 2023/9/18
 * Skill:
 * Runtime: 382 ms, faster than 17.86% of C++ online submissions
 * Memory Usage: 146.08 MB, less than 6.36% of C++ online submissions
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
        vector<pairs> end_times;
        for (int i = 0; i <sz; i++)
            end_times.push_back({i + questions[i][1], i});
        sort(begin(end_times), end(end_times));
        dp[0][1] = questions[0][0];
        int pos = 0;
        ll rolling_max = 0;
        for (int i = 1; i < sz; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            while (pos < sz && end_times[pos].first < i) {
                rolling_max = max(rolling_max, dp[end_times[pos].second][1]);
                pos++;
            }
            dp[i][1] = rolling_max + questions[i][0];
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