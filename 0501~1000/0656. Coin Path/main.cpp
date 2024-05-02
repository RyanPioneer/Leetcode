/**
 * Source: t.ly/OR4EP
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 16.22 MB, less than 52.38% of C++ online submissions
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

const int MX = 1e3+2;

class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        int dp[MX], next[MX], n = coins.size();

        if (coins[n - 1] == -1) return {};
        fill(next, next + MX, -1);
        dp[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (coins[i] == -1) {
                dp[i] = -1;
                continue;
            }
            dp[i] = -1;
            int mi = INT32_MAX / 2;
            for (int j = 1; i + j < n && j <= maxJump; j++) {
                if (dp[i + j] == -1) continue;
                if (dp[i + j] < mi) {
                    mi = dp[i + j];
                    next[i] = i + j;
                }
            }
            if (mi < INT32_MAX / 2) dp[i] = coins[i] + mi;

        }

        vector<int> res;
        if (dp[0] == -1) return res;
        int pos = 0;
        while (pos != n - 1) {
            res.push_back(pos + 1);
            pos = next[pos];
        }
        res.push_back(n);
        return res;
    }
};