/**
 * Source: https://rb.gy/59lrp
 * Date: 2023/9/9
 * Skill:
 * Runtime: 86 ms, faster than 74.73% of C++ online submissions
 * Memory Usage: 17.56 MB, less than 49.82% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    ll dp[101][101];
    ll dis[101][101][101];
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int robot_num = robot.size(), fac_num = factory.size();
        sort(factory.begin(), factory.end());
        sort(robot.begin(), robot.end());
        for (int i = 0; i < fac_num; i++)
            for (int j = 0; j < robot_num; j++) {
                ll sum = 0;
                for (int k = j; k < robot_num && k - j < factory[i][1]; k++) {
                    sum += abs(robot[k] - factory[i][0]);
                    dis[i][j][k] = sum;
                }
            }

        for (int i = 1; i <= robot_num; i++)
            if (i <= factory[0][1])
                dp[0][i] = dis[0][0][i - 1];
            else
                dp[0][i] = LLONG_MAX/2;

        for (int i = 1; i < fac_num; i++)
            for (int j = 1; j <= robot_num; j++) {
                dp[i][j] = dp[i - 1][j];
                for (int k = 1; k <= min(j, factory[i][1]); k++)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + dis[i][j - k][j - 1]);
            }

        return dp[fac_num - 1][robot_num];
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> nums{1,2,3};
}