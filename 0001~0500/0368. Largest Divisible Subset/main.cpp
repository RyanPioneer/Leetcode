/**
 * Source: t.ly/GYZ9B
 * Date: 2024/5/30
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 23.34% of C++ online submissions
 * Memory Usage: 11.27 MB, less than 92.38% of C++ online submissions
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
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), globalMx = 0, head = n;
        vector<int> dp(n), next(n, n), res;
        sort(begin(nums), end(nums));

        for (int i = n-1; i >= 0; i--) {
            int mx = 0;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] % nums[i] == 0 && dp[j] > mx) {
                    next[i] = j;
                    mx = dp[j];
                }
            }
            dp[i] = mx + 1;
            if (dp[i] > globalMx) {
                globalMx = dp[i];
                head = i;
            }
        }

        while (head < n) {
            res.push_back(nums[head]);
            head = next[head];
        }
        return res;
    }
};