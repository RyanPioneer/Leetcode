/**
 * Source: t.ly/-wF4E
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 149 ms, faster than 42.68% of C++ online submissions
 * Memory Usage: 120.59 MB, less than 53.66% of C++ online submissions
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
const int MX = 1e5+2;


class Solution {
public:
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
        int n = regular.size();
        vector<long long> res;
        ll dp[MX][2] = {0};
        dp[0][1] = expressCost;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + regular[i - 1];
            dp[i][1] = min(dp[i - 1][0] + expressCost, dp[i - 1][1]) + express[i - 1];
            res.push_back(min(dp[i][0], dp[i][1]));
        }
        return res;
    }
};