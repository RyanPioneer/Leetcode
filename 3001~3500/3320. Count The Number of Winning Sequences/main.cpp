/**
 * Source: is.gd/d6sGiO
 * Date: 2025/1/22
 * Skill:
 * Ref:
 * Runtime: 257 ms, faster than 88.38% of C++ online submissions
 * Memory Usage: 172.04 MB, less than 44.44% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= s.length <= 1000
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
const int MOD = 1e9+7;


class Solution {
public:
    int countWinningSequences(string s) {
        int n = s.size();
        int offset = n/2;
        vector<vector<array<ll, 3>>> dp(n, vector<array<ll, 3>>(n+offset+1, {0, 0, 0}));

        auto getType = [&](char c) {
            if (c == 'F') return 0;
            if (c == 'W') return 1;
            return 2;
        };

        auto getPoint = [&](int a, int b) {
            if (a == b) return 0;
            if (a == 0) {
                if (b == 2) {
                    return 1;
                } else if (b == 1) {
                    return -1;
                }
            } else if (a == 1) {
                if (b == 0) {
                    return 1;
                } else if (b == 2) {
                    return -1;
                }
            } else {
                if (b == 0) {
                    return -1;
                } else if (b == 1) {
                    return 1;
                }
            }
            return 0;
        };

        for (int i = 0; i < 3; i++) {
            if (getPoint(i, getType(s[0])) + offset >= 0 && getPoint(i, getType(s[0])) + offset <= offset + n) {
                dp[0][getPoint(i, getType(s[0])) + offset][i] = 1;
            }
        }
        
        for (int i = 1; i < n; i++) {
            int aliceType = getType(s[i]);
            for (int j = 0; j <= offset + n; j++) {
                for (int bobType = 0; bobType < 3; bobType++) {
                    int point = getPoint(bobType, aliceType);
                    if (j - point >= 0 && j - point <= offset + n) {
                        for (int k = 0; k < 3; k++) {
                            if (k == bobType) continue;
                            dp[i][j][bobType] = (dp[i][j][bobType] + dp[i-1][j-point][k]) % MOD;
                        }
                    }
                }
            }
        }

        ll res = 0;
        for (int j = offset+1; j <= offset + n; j++) {
            for (int k = 0; k < 3; k++) {
                res += dp[n-1][j][k];
            }
        }
        return (res % MOD + MOD) % MOD;
    }
};
