/**
 * Source: https://rb.gy/kas11
 * Date: 2023/8/29
 * Skill:
 * Runtime: 68 ms, faster than 100% of C++ online submissions
 * Memory Usage: 92.69 MB, less than 26.42% of C++ online submissions
 * Time complexity: O(n log(n))
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<ll> presum(nums.size() + 1, 0);
        ll res = 0, total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            presum[i + 1] = presum[i] + nums[i];
        }
        for (int i = 0; i < nums.size() - 1; i++) {
            if (presum[i + 1] >= total - presum[i + 1])
                res++;
        }
        return res;
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
    vector<vector<int>> edges {{3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}};

}