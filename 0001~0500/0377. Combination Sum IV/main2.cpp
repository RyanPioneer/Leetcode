/**
 * Source: https://rb.gy/f8dum
 * Date: 2023/9/9
 * Skill:
 * Runtime: 3 ms, faster than 50.37% of C++ online submissions
 * Memory Usage: 6.62 MB, less than 46.24% of C++ online submissions
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

//#define ll long long

typedef pair<int, int> pairs;


#define ll unsigned long long
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<ll> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (auto n: nums)
                if (i - n >= 0)
                    dp[i] += dp[i - n];
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
    vector<int> nums{1,2,3};
    int res = s.combinationSum4(nums, 4);
    cout << res << endl;
}