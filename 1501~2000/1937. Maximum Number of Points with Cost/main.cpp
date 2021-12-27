/** 
 * Source: https://leetcode.com/problems/maximum-number-of-points-with-cost/
 * Date: 2021/7/19
 * Skill: DP
 * Runtime: 
 * Memory Usage: 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= m, n <= 10^5
 *      0 <= points[r][c] <= 10^5
 */

#include<iostream>
#include<vector>
using namespace std;

typedef struct point{
    int num;
    int offset;
    point(int a, int b):num(a), offset(b){};
}Point;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        long long ans = 0;
        vector<vector<Point>> dp(points.size(), vector<Point>(points[0].size(), Point(-1, 0)));
        for (int i = 0; i < points[0].size(); i++) {
            dp[0][i].num = points[0][i];
            dp[0][i].offset = i;
        }
        for (int j = 1; j < points.size(); j++) {
            dp[j][0].num = points[j][0] + dp[j-1][0].num;
            dp[j][0].offset = 0;
        }
        for (int i = 1; i < points.size(); i++) {
            for (int j = 1; j < points[0].size(); j++) {
                if (dp[i-1][j].num + )
            }
        }
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();