/**
 * Source: is.gd/K3wvYu
 * Date: 2024/2/24
 * Skill:
 * Ref:
 * Runtime: 2011 ms, faster than 5.00% of C++ online submissions
 * Memory Usage: 456.20 MB, less than 9.17% of C++ online submissions
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

const int MX = 1e6+2;


class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int, int> cnt;
        int dp[MX][2] = {0}, res = 1, mx = *max_element(begin(nums), end(nums));
        int mi = *min_element(begin(nums), end(nums));
        for (auto &i: nums) cnt[i]++;
        for (int i = mi; i <= mx + 1; i++) {
            if (cnt[i] > 0) {
                dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
                if (cnt[i - 1] > 0) dp[i][0] = dp[i - 1][0] + 1;
                if (cnt[i - 1] > 1) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
                res = max({res, dp[i][0], dp[i][1]});
            } else {
                if (cnt[i - 1] > 0) dp[i][0] = dp[i - 1][0] + 1;
                if (cnt[i - 1] > 1) dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
                res = max(res, dp[i][0]);
            }
        }
        return res;
    }
};