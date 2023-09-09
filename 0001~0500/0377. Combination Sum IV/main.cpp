/**
 * Source: https://rb.gy/f8dum
 * Date: 2023/9/9
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 6.84 MB, less than 12.44% of C++ online submissions
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
    vector<int> dp;
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return helper(nums, target);
    }
    int helper(vector<int>& nums, int target) {
        if (target == 0)
            return 1;
        if (dp[target] != -1)
            return dp[target];
        int res = 0;
        for (auto n: nums)
            if (n <= target)
                res += helper(nums, target - n);
        dp[target] = res;
        return dp[target];
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

}