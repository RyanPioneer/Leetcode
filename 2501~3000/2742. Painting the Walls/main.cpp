/**
 * Source: t.ly/EwrcQ
 * Date: 2023/10/14
 * Skill:
 * Runtime: 290 ms, faster than 17.01% of C++ online submissions
 * Memory Usage: 91.50 MB, less than 65.68% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= cost.length <= 500
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
    int offset = 500;
    int dp[501][501 * 2];
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int sz = cost.size(), res = INT32_MAX;
        cost.insert(begin(cost), 0);
        time.insert(begin(time), 0);
        for (int i = 0; i <= sz; i++)
            for (int j = -sz; j <= sz; j++)
                dp[i][j + offset] = INT32_MAX / 2;
        dp[0][0 + offset] = 0;
        for (int i = 0; i < sz; i++) {
            for (int j = -sz; j <= sz; j++) {
                if (j + 1 <= sz)
                    dp[i+1][j + offset] = min(dp[i+1][j + offset], dp[i][j + 1 + offset]);
                dp[i+1][min(j + time[i + 1], sz) + offset] = min(dp[i+1][min(j + time[i + 1], sz) + offset], dp[i][j + offset] + cost[i + 1]);
            }
        }
        for (int i = 0; i <= sz; i++)
            res = min(res, dp[sz][i + offset]);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}