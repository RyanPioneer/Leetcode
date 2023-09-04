/**
 * Source: https://rb.gy/1fej1
 * Date: 2023/9/4
 * Skill:
 * Runtime: 16 ms, faster than 24.32% of C++ online submissions
 * Memory Usage: 13.76 MB, less than 15.39% of C++ online submissions
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
        unordered_map<int, int> num2count;
        vector<int> nums = arr;
        sort(begin(nums), end(nums));
        int lack = 0, res = 0;
        for (int i = 0; i < nums.size(); i++) {
            num2count[nums[i]]--;
            lack++;
            if (num2count[nums[i]] >= 0)
                lack--;
            num2count[arr[i]]++;
            if (num2count[arr[i]] <= 0)
                lack--;
            if (lack == 0)
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