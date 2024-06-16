/**
 * Source: t.ly/3O-iR
 * Date: 2024/6/6
 * Skill:
 * Ref:
 * Runtime: 35 ms, faster than 82.25% of C++ online submissions
 * Memory Usage: 14.98 MB, less than 67.46% of C++ online submissions
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


const int MX = 1e3+7;


class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        int n = present.size(), dp[MX] = {0};
        for (int i = 0; i < n; i++) {
            for (int j = budget; j >= 0; j--) {
                if (j - present[i] >= 0) {
                    dp[j] = max(dp[j], dp[j - present[i]] + future[i] - present[i]);
                }
            }
        }
        return *max_element(dp, dp + budget + 1);
    }
};