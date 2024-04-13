/**
 * Source: is.gd/NGw32l
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 105 ms, faster than 87.84% of C++ online submissions
 * Memory Usage: 87.62 MB, less than 45.34% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

const int MX = 31;


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) return 1;
        int n = nums.size(), cnt[MX] = {0};
        int res = n + 1, right = 0, cur_sum = 0;
        for (int left = 0; left < n; left++) {
            while (cur_sum < k && right < n) {
                cur_sum |= nums[right];
                for (int j = 0; j < MX; j++) {
                    if (((nums[right] >> j) & 1) != 0) cnt[j]++;
                }
                right++;
            }
            if (cur_sum < k) break;
            res = min(res, right - left);
            for (int j = 0; j < MX; j++) {
                if (((nums[left] >> j) & 1) != 0) {
                    cnt[j]--;
                    if (cnt[j] == 0) cur_sum -= (1 << j);
                }
            }
        }
        return res <= n ? res : -1;
    }
};