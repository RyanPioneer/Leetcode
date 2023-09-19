/**
 * Source: https://rb.gy/s17u8
 * Date: 2023/9/18
 * Skill:
 * Runtime: 254 ms, faster than 95.86% of C++ online submissions
 * Memory Usage: 115.55 MB, less than 64.23% of C++ online submissions
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
        vector<ll> dp(sz);
        dp[sz - 1] = questions[sz - 1][0];
        for (int i = sz - 2; i >= 0; i--) {
            int next_pos = i + questions[i][1] + 1;
            dp[i] = max(dp[i + 1], questions[i][0] + (next_pos < sz ? dp[next_pos] : 0));
        }
        return dp[0];
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