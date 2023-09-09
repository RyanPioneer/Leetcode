/**
 * Source: https://rb.gy/vqg6k
 * Date: 2023/9/8
 * Skill:
 * Runtime: 154 ms, faster than 5.73% of C++ online submissions
 * Memory Usage: 72.85 MB, less than 45.26% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 13
 *      -9 <= nums[i] <= 9
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
    long long maxStrength(vector<int>& nums) {
        int sz = nums.size();
        vector<ll> res(1 << sz);
        res[0] = LLONG_MIN;
        for (int i = 1; i < (1 << sz); i++) {
            ll num = 1;
            for (int j = 0; j < sz; j++)
                if ((i >> j) & 1 != 0)
                    num *= nums[j];
            res[i] = num;
        }
        return *max_element(begin(res), end(res));
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
    vector<int> nums{2,3,6};
}