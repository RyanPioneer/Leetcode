/**
 * Source: ibit.ly/Kd5ye
 * Date: 2024/6/25
 * Skill:
 * Ref:
 * Runtime: 107 ms, faster than 89.80% of C++ online submissions
 * Memory Usage: 26.27 MB, less than 89.27% of C++ online submissions
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
ll MOD = 1e9+7;


class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        ll dp[310][410] = {0};
        dp[0][0] = 1;
        map<int, int> mp;
        for (auto &i: requirements) {
            mp[i[0]+1] = i[1];
        }
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            int limit = mp.lower_bound(i)->second;
            if (mp.find(i) != end(mp)) {
                cur = mp[i];
            }
            for (int j = cur; j <= limit; j++) {
                for (int k = 0; k <= j; k++) {
                    if (j - k <= i - 1) {
                        dp[i][j] = (dp[i][j] + dp[i-1][k]) % MOD;
                    }
                }
            }
        }
        return dp[n][cur];
    }
};