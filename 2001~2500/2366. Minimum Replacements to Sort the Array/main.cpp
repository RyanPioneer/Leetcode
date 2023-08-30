/**
 * Source: https://rb.gy/2cnul
 * Date: 2023/8/30
 * Skill:
 * Runtime: 108 ms, faster than 53.15% of C++ online submissions
 * Memory Usage: 54.61 MB, less than 42.04% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
    long long minimumReplacement(vector<int>& nums) {
        ll res = 0;
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            int a = nums[i] / nums[i + 1], b = nums[i] % nums[i + 1];
            if (b == 0) {
                nums[i] = nums[i + 1];
                res += a - 1;
                continue;
            }
            // b + a * d <= nums[i + 1] - d, d <= (nums[i + 1] - b) / (a + 1)
            int d = (nums[i + 1] - b) / (a + 1);
            b += a * d;
            nums[i] = (b == nums[i + 1] - d) ? b : nums[i + 1] - d - 1;
            res += a;
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
    vector<int> tasks{1,2,3,1};
}