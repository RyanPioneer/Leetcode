/**
 * Source: ibit.ly/agOjH
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 418 ms, faster than 20.59% of C++ online submissions
 * Memory Usage: 145.86 MB, less than 94.12% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int res = 0, n = nums.size();
        int right[MX], curMax = nums.back();

        for (int i = n - 1; i >= 0; i--) {
            right[i] = curMax > nums[i] ? curMax : INT32_MIN / 2;
            curMax = max(curMax, nums[i]);
        }

        set<int> left;
        for (int i = 0; i < n; i++) {
            if (left.lower_bound(nums[i]) != begin(left)) {
                res = max(res, *prev(left.lower_bound(nums[i])) - nums[i] + right[i]);
            }
            left.insert(nums[i]);
        }
        return res;
    }
};