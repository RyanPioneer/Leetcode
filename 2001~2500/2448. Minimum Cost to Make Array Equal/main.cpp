/**
 * Source: https://rb.gy/a30a3
 * Date: 2023/8/29
 * Skill:
 * Runtime: 72 ms, faster than 83.16% of C++ online submissions
 * Memory Usage: 44.6 MB, less than 22.84% of C++ online submissions
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
    long long minCost(vector<int>& nums, vector<int>& cost) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < nums.size(); i++)
            arr.push_back({nums[i], cost[i]});
        sort(arr.begin(), arr.end());
        vector<ll> left(nums.size(), 0), right(nums.size(), 0);
        ll left_sum = arr[0].second, right_sum = arr[nums.size() - 1].second, res = LLONG_MAX;
        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] + left_sum * (arr[i].first - arr[i - 1].first);
            left_sum += arr[i].second;
            right[nums.size() - 1 - i] = right[nums.size() - i] +
                    right_sum * (arr[nums.size() - i].first - arr[nums.size() - 1 - i].first);
            right_sum += arr[nums.size() - 1 - i].second;
        }
        for (int i = 0; i < nums.size(); i++)
            res = min({res, left[i] + right[i]});
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

}