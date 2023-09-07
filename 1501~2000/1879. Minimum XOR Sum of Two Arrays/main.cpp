/**
 * Source: https://rb.gy/20gjg
 * Date: 2023/9/7
 * Skill:
 * Runtime: 10 ms, faster than 98.92% of C++ online submissions
 * Memory Usage: 9.52 MB, less than 82.25% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 14
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
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> dp(1 << n, INT32_MAX / 2);
        dp[0] = 0;
        for (int state = 1; state < (1 << n); state++) {
            int bit_num = __builtin_popcount(state);
            for (int j = 0; j < n; j++) {
                if (((state >> j) & 1) != 0) {
                    dp[state] = min(dp[state], dp[state - (1 << j)] + (nums1[bit_num - 1] ^ nums2[j]));
                }
            }
        }
        return dp[(1 << n) - 1];
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
    vector<int> nums1{1,2};
    vector<int> nums2{2,3};
    int res = s.minimumXORSum(nums1, nums2);
    cout << res << endl;
}