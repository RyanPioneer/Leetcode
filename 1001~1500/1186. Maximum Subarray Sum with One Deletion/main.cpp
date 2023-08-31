/**
 * Source: https://rb.gy/3x4l9
 * Date: 2023/8/31
 * Skill: kadane algorithm variation
 * Runtime: 46 ms, faster than 21.96% of C++ online submissions
 * Memory Usage: 29.9 MB, less than 18.64% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= arr.length <= 10 ** 5
 *      -10 ** 4 <= arr[i] <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> dp(2, 0);
        dp[0] = arr[0], dp[1] = 0;
        int res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            vector<int> dp2 = dp;
            dp[0] = max(dp2[0] + arr[i], arr[i]), dp[1] = max(dp2[0], dp2[1] + arr[i]);
            res = max({res, dp[0], dp[1]});
        }
        return res;
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
    vector<int> arr{11,-10,-11,8,7,-6,9,4,11,6,5,0};
    int res = s.maximumSum(arr);
    cout << res << endl;
}