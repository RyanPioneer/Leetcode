/**
 * Source: ibit.ly/folsj
 * Date: 2023/9/28
 * Skill:
 * Runtime: 27 ms, faster than 75.53% of C++ online submissions
 * Memory Usage: 7.81 MB, less than 44.49% of C++ online submissions
 * Time complexity: O(n)
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int sz = jobDifficulty.size();
        if (sz < d)
            return -1;
        vector<int> dp(sz), dp2(sz);
        dp[0] = jobDifficulty[0];
        for (int i = 1; i < sz; i++)
            dp[i] = max(dp[i - 1], jobDifficulty[i]);
        for (int i = 2; i <= d; i++) {
            dp2 = dp;
            dp[i - 1] = dp2[i - 2] + jobDifficulty[i - 1];
            for (int j = i; j < sz; j++) {
                int cur_max = jobDifficulty[j];
                dp[j] = dp2[j - 1] + cur_max;
                for (int k = j - 1; k >= i - 1; k--) {
                    cur_max = max(cur_max, jobDifficulty[k]);
                    dp[j] = min(dp[j], dp2[k - 1] + cur_max);
                }
            }
        }
        return dp[sz - 1];
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}