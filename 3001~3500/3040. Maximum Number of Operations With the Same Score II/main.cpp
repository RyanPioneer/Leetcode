/**
 * Source: is.gd/pQwaE8
 * Date: 2024/2/24
 * Skill:
 * Ref:
 * Runtime: 261 ms, faster than 40.91% of C++ online submissions
 * Memory Usage: 39.57 MB, less than 97.07% of C++ online submissions
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

const int MX = 2002;


class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int sz = nums.size(), dp[MX][MX] = {0};
        if (sz == 2) return 1;
        dp[2][sz - 1] = nums[0] + nums[1], dp[0][sz - 3] = nums[sz - 2] + nums[sz - 1];
        dp[1][sz - 2] = nums[0] + nums[sz - 1];
        for (int len = sz - 2; len > 1; len -= 2) {
            bool found = false;
            for (int left = 0; left + len <= sz; left++) {
                int right = left + len - 1;
                if (dp[left][right] == nums[left] + nums[left + 1]) {
                    found = true;
                    dp[left + 2][right] = dp[left][right];
                }
                if (dp[left][right] == nums[right] + nums[right - 1]) {
                    found = true;
                    if (right - 2 < 0) return sz / 2;
                    dp[left][right - 2] = dp[left][right];
                }
                if (dp[left][right] == nums[left] + nums[right]) {
                    found = true;
                    dp[left + 1][right - 1] = dp[left][right];
                }
            }
            if (!found) return (sz - len) / 2;
        }
        return sz / 2;
    }
};