/**
 * Source: jpeg.ly/HzDPG
 * Date: 2024/1/21
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 30.61 MB, less than 33.33% of C++ online submissions
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


class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int idx = 0, sz = nums.size();
        int prev_max = INT32_MIN;
        while (idx < sz) {
            int cur_max = nums[idx], cur_min = nums[idx];
            while (idx + 1 < sz && __builtin_popcount(nums[idx]) == __builtin_popcount(nums[idx + 1])) {
                idx++;
                cur_max = max(cur_max, nums[idx]);
                cur_min = min(cur_min, nums[idx]);
            }
            if (prev_max > cur_min) return false;
            prev_max = cur_max;
            idx++;
        }
        return true;
    }
};