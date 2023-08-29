/**
 * Source: https://rb.gy/3hx0v
 * Date: 2023/8/29
 * Skill:
 * Runtime: 123 ms, faster than 82.08% of C++ online submissions
 * Memory Usage: 88.3 MB, less than 22.62% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int sz = nums.size(), min_pos = min_element(begin(nums), end(nums)) - begin(nums), max_pos = max_element(begin(nums), end(nums)) - begin(nums);
        if (min_pos > max_pos) swap(min_pos, max_pos);
        return min({min_pos + 1 + sz - max_pos, sz - min_pos, max_pos + 1});
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