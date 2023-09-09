/**
 * Source: https://rb.gy/vqg6k
 * Date: 2023/9/8
 * Skill:
 * Runtime: 14 ms, faster than 69.75% of C++ online submissions
 * Memory Usage: 46.6 MB, less than 84.8% of C++ online submissions
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
        sort(nums.begin(), nums.end());
        ll res = 1, cnt = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] <= 0)
                break;
            res *= nums[i];
            cnt++;
        }
        for (int i = 0; i + 1 < nums.size(); i+=2) {
            if (nums[i + 1] >= 0)
                break;
            res *= nums[i] * nums[i + 1];
            cnt+=2;
        }
        return cnt > 0 ? res : nums.back();
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