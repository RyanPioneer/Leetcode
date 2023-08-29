/**
 * Source: https://rb.gy/i6gfs
 * Date: 2023/8/29
 * Skill:
 * Runtime: 97 ms, faster than 87.61% of C++ online submissions
 * Memory Usage: 53.82 MB, less than 62.82% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
 *      1 <= nums[i] <= 10 ** 5
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ll res = 0, mod = 1e9+7, count = 1, presum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res += count * nums[i] - presum;
            res %= mod;
            presum = (2 * presum + nums[i]) % mod;
            count = (count * 2 + 1) % mod;
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
    vector<int> tasks{3,7,2,3};
    auto res = s.sumSubseqWidths(tasks);
    cout << res << endl;
}