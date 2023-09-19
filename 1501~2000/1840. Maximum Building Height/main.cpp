/**
 * Source: https://rb.gy/fgvma
 * Date: 2023/9/19
 * Skill: 先確立好被限制的房子高度，分別從左往右跟由右往左掃。
 * Runtime: 414 ms, faster than 62.79% of C++ online submissions
 * Memory Usage: 104.42 MB, less than 36.05% of C++ online submissions
 * Time complexity: O(nlog(n))
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
#include <bitset>

using namespace std;


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty())
            return n - 1;
        sort(restrictions.begin(), restrictions.end());
        int sz = restrictions.size(), res = 0;
        vector<int> nums(sz);
        nums[0] = min(restrictions[0][1], restrictions[0][0] - 1);
        for (int i = 1; i < sz; ++i) {
            int idx = restrictions[i][0], limit = restrictions[i][1];
            int prev_idx = restrictions[i - 1][0], prev_height = nums[i - 1];
            if (prev_height + idx - prev_idx < limit)
                nums[i] = prev_height + idx - prev_idx;
            else
                nums[i] = limit;
        }
        res = nums[sz - 1] + (n - restrictions[sz - 1][0]);
        for (int i = sz - 2; i >= 0; i--) {
            int idx = restrictions[i][0], next_idx = restrictions[i + 1][0];
            nums[i] = min(nums[i], nums[i + 1] + (next_idx - idx));
            int space = next_idx - idx - abs(nums[i] - nums[i + 1]);
            res = max(res, max(nums[i], nums[i + 1]) + space / 2);
        }
        int space = restrictions[0][0] - 1 - nums[0];
        return max(res, nums[0] + space / 2);
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    int res = s.maxBuilding(10, arr1);
    cout << res << endl;
}