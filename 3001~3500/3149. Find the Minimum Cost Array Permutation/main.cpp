/**
 * Source: ibit.ly/Hgy-p
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 257 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 78.78 MB, less than 100.00% of C++ online submissions
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
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(1 << n, vector<int>(n, -1));

        function<int(int, int)> dfs = [&](int state, int lastNum) {
            if (state == (1 << n) - 1) {
                return abs(lastNum - nums[0]);
            }
            if (memo[state][lastNum] != -1) {
                return memo[state][lastNum];
            }
            int mi = INT_MAX;
            for (int i = 1; i < n; i++) {
                if ((state >> i & 1) == 0) {
                    mi = min(mi, dfs(state | (1 << i), i) + abs(lastNum - nums[i]));
                }
            }
            return memo[state][lastNum] = mi;
        };

        vector<int> res;

        function<void(int, int)> findRes = [&](int state, int lastNum) {
            res.push_back(lastNum);
            if (state == (1 << n) - 1) {
                return;
            }
            int mi = dfs(state, lastNum);
            for (int i = 1; i < n; i++) {
                if ((state >> i & 1) == 0 && dfs(state | (1 << i), i) + abs(lastNum - nums[i]) == mi) {
                    findRes(state | 1 << i, i);
                    break;
                }
            }
        };

        findRes(1, 0);
        return res;
    }
};