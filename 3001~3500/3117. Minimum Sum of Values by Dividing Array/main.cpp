/**
 * Source: is.gd/P0e5oV
 * Date: 2024/4/15
 * Skill:
 * Ref:
 * Runtime: 3360 ms, faster than 14.29% of C++ online submissions
 * Memory Usage: 256.80 MB, less than 28.57% of C++ online submissions
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
#define ll long long


class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = nums.size(), m = andValues.size();
        unordered_map<ll, int> memo;

        function<int(int, int, int)> dfs = [&](int idx, int slice, int andValue) {
            if (idx == n) return slice == m ? 0 : INT_MAX;
            if (slice == m) return INT_MAX;
            andValue &= nums[idx];

            ll mask = ((ll)idx << 36) | (ll)slice << 32 | andValue;

            if (memo.find(mask) != end(memo)) return memo[mask];
            if (andValue < andValues[slice]) return INT_MAX;

            int res = dfs(idx + 1, slice, andValue);

            if (andValue == andValues[slice]) {
                int val = dfs(idx + 1, slice + 1, -1);

                if (val < INT_MAX) {
                    res = min(res, val + nums[idx]);
                }
            }
            return memo[mask] = res;
        };

        int ans = dfs(0, 0, -1);

        return ans < INT_MAX ? ans : -1;
    }
};