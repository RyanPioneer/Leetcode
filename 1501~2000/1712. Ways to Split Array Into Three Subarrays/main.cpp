/**
 * Source: https://rb.gy/ydwhl
 * Date: 2023/8/29
 * Skill:
 * Runtime: 112 ms, faster than 92.70% of C++ online submissions
 * Memory Usage: 88.62 MB, less than 8.11% of C++ online submissions
 * Time complexity: O(n log(n))
 * Space complexity: O(n)
 * Constraints:
 *      3 <= nums.length <= 10 ** 5
 *      0 <= nums[i] <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;


class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        ll mod = 1e9+7;
        vector<ll> presum(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            presum[i + 1] = presum[i] + nums[i];
        ll res = 0, pos = 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            ll left = presum[i + 1];
            while (pos < nums.size() - 1 && (presum[pos + 1] - left < left || pos <= i))
                pos++;
            if (pos == nums.size() - 1)
                break;
            if (presum[nums.size()] - presum[pos + 1] < presum[pos + 1] - left)
                continue;
            int pos2 = binary_search(nums, presum, left, pos, nums.size() - 2);
            res += pos2 - pos + 1;
            res %= mod;
        }
        return res;
    }
    int binary_search(vector<int>& nums, vector<ll>& presum, ll left, int l, int r) {
        while (l < r) {
            int m = (l + r + 1) / 2;
            ll mid = presum[m + 1] - left, right = presum[nums.size()] - presum[m + 1];
            if (mid > right)
                r = m - 1;
            else
                l = m;
        }
        return r;
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;
    vector<int> tasks{1,2,2,2,5,0};
    int res = s.waysToSplit(tasks);
    cout << res << endl;
}