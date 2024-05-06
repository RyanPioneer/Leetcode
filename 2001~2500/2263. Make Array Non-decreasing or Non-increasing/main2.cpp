/**
 * Source: t.ly/J7Wc_
 * Date: 2024/5/4
 * Skill:
 * Ref:
 * Runtime: 452 ms, faster than 12.50% of C++ online submissions
 * Memory Usage: 16.09 MB, less than 37.50% of C++ online submissions
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
    int convertArray(vector<int>& nums) {
        set<int> levels(begin(nums), end(nums));

        function<int()> helper = [&]() {
            unordered_map<int, int> dp;
            for (auto &i: nums) {
                int curRes = INT_MAX;
                for (auto &j: levels) {
                    curRes = min(curRes, dp[j] + abs(j - i));
                    dp[j] = curRes;
                }
            }
            return dp[*--end(levels)];
        };

        int res = helper();
        reverse(begin(nums), end(nums));
        res = min(res, helper());
        return res;
    }
};