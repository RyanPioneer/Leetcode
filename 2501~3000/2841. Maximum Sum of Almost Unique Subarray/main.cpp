/**
 * Source: https://rb.gy/800gz
 * Date: 2023/9/3
 * Skill:
 * Runtime: 185 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 82.31 MB, less than 16.67% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_set<int> num_set;
        unordered_map<int, int> num2count;
        ll res = 0, cur_sum = 0;
        for (int i = 0; i < k; i++) {
            cur_sum += nums[i];
            num_set.insert(nums[i]);
            num2count[nums[i]]++;
        }
        if (num_set.size() >= m)
            res = cur_sum;
        for (int i = k; i < nums.size(); i++) {
            num2count[nums[i - k]]--;
            if (num2count[nums[i - k]] == 0)
                num_set.erase(nums[i - k]);
            cur_sum += nums[i] - nums[i - k];
            num2count[nums[i]]++;
            num_set.insert(nums[i]);
            if (num_set.size() >= m)
                res = max(res, cur_sum);
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
    vector<vector<int>> nums{{0, 1}, {1, 2}, {2, 0}, {1, 3}};

}