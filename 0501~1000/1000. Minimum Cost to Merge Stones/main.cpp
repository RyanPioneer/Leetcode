/**
 * Source: is.gd/LIMekz
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 60.93% of C++ online submissions
 * Memory Usage: 8.49 MB, less than 77.73% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 31;


class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int dp[MX][MX][MX], presum[MX] = {0}, n = SZ(stones);
        if ((n - 1) % (K - 1) != 0) return -1;
        fill(dp[0][0], dp[MX - 1][MX - 1] + MX, INT32_MAX);
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + stones[i];
            dp[i][i][1] = 0;
        }
        for (int len = 2; len <= n; len++) {
            for (int start = 0; start + len <= n; start++) {
                int end = start + len - 1;
                for (int k = 2; k <= min(len, K); k++) {
                    for (int mid = start; mid < end; mid++) {
                        if (dp[start][mid][1] != INT32_MAX && dp[mid + 1][end][k - 1] != INT32_MAX) {
                            dp[start][end][k] = min(dp[start][end][k], dp[start][mid][1] + dp[mid + 1][end][k - 1]);
                        }
                    }
                }
                if (dp[start][end][K] != INT32_MAX) {
                    dp[start][end][1] = min(dp[start][end][1], dp[start][end][K] + presum[end + 1] - presum[start]);
                }
            }
        }
        return dp[0][n - 1][1] == INT32_MAX ? -1 : dp[0][n - 1][1];
    }
};