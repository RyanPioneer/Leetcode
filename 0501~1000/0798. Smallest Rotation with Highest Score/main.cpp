/**
 * Source: https://rb.gy/4mkfc
 * Date: 2023/9/7
 * Skill: 差分數組
 * Runtime: 93 ms, faster than 86.67% of C++ online submissions
 * Memory Usage: 74.47 MB, less than 73.33% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
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
    int bestRotation(vector<int>& nums) {
        int sz = nums.size(), cur = 0, max_num = 0, res = 0;
        vector<int> diff(sz + 1, 0);
        for (int i = 0; i < sz; i++) {
            if (nums[i] == 0)
                continue;
            if (nums[i] <= i) {
                diff[0]++;
                diff[i - nums[i] + 1]--;
                diff[i + 1]++;
            } else {
                diff[i + 1]++;
                diff[i + sz - nums[i] + 1]--;
            }
        }
        for (int i = 0; i < sz; i++) {
            cur += diff[i];
            if (cur > max_num) {
                res = i;
                max_num = cur;
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
    vector<int> row{1,3,0,2,4};
    int res = s.bestRotation(row);
    cout << res << endl;
}