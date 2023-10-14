/**
 * Source: t.ly/EwrcQ
 * Date: 2023/10/14
 * Skill:
 * Runtime: 91 ms, faster than 94.38% of C++ online submissions
 * Memory Usage: 90.26 MB, less than 73.95% of C++ online submissions
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
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int sz = cost.size();
        cost.insert(begin(cost), 0);
        time.insert(begin(time), 0);
        int dp[501][501];
        for (int i = 0; i <= sz; i++)
            for (int j = 0; j <= sz; j++)
                dp[i][j] = INT32_MAX / 2;
        dp[0][0] = 0;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j <= sz; j++) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
                dp[i + 1][min(sz, j + time[i + 1] + 1)] = min(dp[i + 1][min(sz, j + time[i + 1] + 1)], dp[i][j] + cost[i + 1]);
            }
        return dp[sz][sz];
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}