/**
 * Source: https://rb.gy/1fej1
 * Date: 2023/9/4
 * Skill:
 * Runtime: 12 ms, faster than 41.72% of C++ online submissions
 * Memory Usage: 12.41 MB, less than 40.07% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= arr.length <= 2000
 *      0 <= arr[i] <= 10 ** 8
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        auto nums = arr;
        sort(begin(nums), end(nums));
        ll sum1 = 0, sum2 = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum1 += nums[i];
            sum2 += arr[i];
            if (sum1 == sum2)
                res++;
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}