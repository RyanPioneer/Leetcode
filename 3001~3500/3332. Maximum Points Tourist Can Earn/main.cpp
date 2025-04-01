/**
 * Source: t.ly/LWDB_
 * Date: 2025/1/23
 * Skill:
 * Ref:
 * Runtime: 283 ms, faster than 84.92% of C++ online submissions
 * Memory Usage: 58.00 MB, less than 75.40% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= n <= 200
 *      1 <= k <= 200
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
const int MX = 201; 


class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        int dp[2][MX] = {0}, res = 0;
        
        for (int i = 1; i <= k; i++) {
            for (int city = 0; city < n; city++) {
                for (int prevCity = 0; prevCity < n; prevCity++) {
                    if (city == prevCity) {
                        dp[i%2][city] = max(dp[i%2][city], dp[(i-1)%2][prevCity] + stayScore[i-1][city]);
                    } else {
                        dp[i%2][city] = max(dp[i%2][city], dp[(i-1)%2][prevCity] + travelScore[prevCity][city]);
                    }
                }
                res = max(res, dp[i%2][city]);
            }
        }

        return res;
    }
};
