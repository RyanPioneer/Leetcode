/**
 * Source: https://rb.gy/vprz5
 * Date: 2023/9/4
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 7.12 MB, less than 54.88% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= arr.length <= 10
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
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_sum = 0, presum = 0, res = 0;
        for (int i = 0; i < arr.size(); i++) {
            cur_sum += arr[i];
            presum += i;
            res += presum == cur_sum;
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