/**
 * Source: https://rb.gy/5effb
 * Date: 2023/9/1
 * Skill:
 * Runtime: 889 ms, faster than 21.12% of C++ online submissions
 * Memory Usage: 221.9 MB, less than 13.87% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 1000
 *      1 <= nums[i] <= nums.length
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            map<int, int> counter;
            counter[nums[i]] = 1;
            int cur_num = 0;
            for (int j = i + 1; j < nums.size(); j++) {
                if (counter[nums[j]] != 0) {
                    res += cur_num;
                    continue;
                }
                cur_num += 1 - counter[nums[j] - 1] - counter[nums[j] + 1];
                res += cur_num;
                counter[nums[j]] = 1;
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
    vector<int> nums{1,3,2};
    int res = s.sumImbalanceNumbers(nums);
    cout << res << endl;
}