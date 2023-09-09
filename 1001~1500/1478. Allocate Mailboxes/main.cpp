/**
 * Source: https://rb.gy/hmfk8
 * Date: 2023/9/8
 * Skill:
 * Runtime: 39 ms, faster than 47.61% of C++ online submissions
 * Memory Usage: 9.2 MB, less than 43.51% of C++ online submissions
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


class Solution {
public:
    int minDistance(vector<int>& houses, int K) {
        int sz = houses.size();
        sort(begin(houses), end(houses));
        vector<vector<int>> dp(sz, vector<int>(K + 1));
        vector<vector<int>> range_dis(sz, vector<int>(sz));
        for (int i = 0; i < sz; i++)
            for (int j = i; j < sz; j++)
                for (int k = i; k <= j; k++)
                    range_dis[i][j] += abs(houses[k] - houses[(i + j) / 2]);
        for (int i = 0; i < sz; i++)
            dp[i][1] = range_dis[0][i];
        for (int i = 2; i <= K; i++) {
            for (int j = sz - 1; j >= 0; j--) {
                dp[j][i] = INT32_MAX / 2;
                for (int k = j - 1; k >= 0; k--)
                    dp[j][i] = min(dp[j][i], dp[k][i - 1] + range_dis[k + 1][j]);
            }
        }
        return dp[sz - 1][K];
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> nums{1,4,8,10,20};
    int res = s.minDistance(nums, 3);
    cout << res << endl;
}