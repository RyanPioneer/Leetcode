/**
 * Source: https://rb.gy/mczt9
 * Date: 2023/9/8
 * Skill:
 * Runtime: 17 ms, faster than 65.90% of C++ online submissions
 * Memory Usage: 15.42 MB, less than 45.26% of C++ online submissions
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
    int smallestRangeII(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = nums.back() - nums[0];
        for (int i = 0; i < nums.size() - 1; i++) {
            int maximum = max(nums[i] + k, nums.back() - k);
            int minimum = min(nums[i + 1] - k, nums[0] + k);
            res = min(res, maximum - minimum);
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
    vector<int> nums{7,8,8,5,2};
    int res = s.smallestRangeII(nums, 4);
    cout << res << endl;
}