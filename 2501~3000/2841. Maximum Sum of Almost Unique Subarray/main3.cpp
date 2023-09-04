/**
 * Source: https://rb.gy/800gz
 * Date: 2023/9/3
 * Skill:
 * Runtime: 136 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 67.69 MB, less than 16.67% of C++ online submissions
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
        int unique_item_num = 0, left = 0, right = 0, sz = nums.size();
        unordered_map<int, int> num2count;
        ll res = 0, cur_sum = 0;
        while (right < sz) {
            do {
                cur_sum += nums[right];
                num2count[nums[right]]++;
                if (num2count[nums[right]] == 1)
                    unique_item_num++;
                right++;
            } while (right < sz && (unique_item_num < m || right - left < k));
            if (unique_item_num < m || right - left < k)
                break;
            while (right - left > k) {
                cur_sum -= nums[left];
                num2count[nums[left]]--;
                if (num2count[nums[left]] == 0)
                    unique_item_num--;
                left++;
            }
            if (unique_item_num >= m)
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