/**
 * Source: https://rb.gy/xggou
 * Date: 2023/8/28
 * Skill:
 * Runtime: 7 ms, faster than 85.71% of C++ online submissions
 * Memory Usage: 22.35 MB, less than 57.14% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<int> count(31, 0);
        for (auto i: nums) {
            int idx = 0;
            while (i > 1) {
                i /= 2;
                idx += 1;
            }
            count[idx] += 1;
        }
        vector<int> t;
        for (int i = 0; i < 31; i++) {
            if ((target >> i) & 1)
                t.push_back(i);
        }
        int res = 0;
        for (auto i: t) {
            int j = 0;
            while (j < i) {
                count[j + 1] += count[j] / 2;
                count[j] %= 2;
                j++;
            }
            if (count[i] > 0) {
                count[i] -= 1;
                continue;
            }
            while (j < 31 && count[j] == 0)
                j++;
            if (j == 31)
                return -1;
            count[j] -= 1;
            res += j - i;
            while (j > i) {
                count[j - 1] += 1;
                j -= 1;
            }
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
    vector<int> nums{1, 2, 8};
    int target = 7;
    int res = s.minOperations(nums, target);
    cout << res << endl;
}