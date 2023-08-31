/**
 * Source: https://rb.gy/fog3u
 * Date: 2023/8/31
 * Skill:
 * Runtime: 287 ms, faster than 85.87% of C++ online submissions
 * Memory Usage: 109.35 MB, less than 75.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <stack>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;


class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        ll mod = 1e9+7, res = 0, max_num = *max_element(begin(nums), end(nums));
        sort(nums.begin(), nums.end());
        vector<int> presum(max_num + 1, 0);
        int pos = 0;
        for (int i = 1; i < presum.size(); i++) {
            presum[i] = presum[i - 1];
            while (pos < nums.size() && nums[pos] == i) {
                presum[i]++;
                pos++;
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            ll num = 0, j = nums[i];
            for (int k = 1; j <= max_num; k++) {
                num += (presum[min(j + nums[i] - 1, max_num)] - presum[j - 1]) * k;
                j += nums[i];
            }
            res += num;
            res %= mod;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
                res += num;
                res %= mod;
            }
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
    string ss = "t";

}