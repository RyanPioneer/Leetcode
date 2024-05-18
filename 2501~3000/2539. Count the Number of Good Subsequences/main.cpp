/**
 * Source: ibit.ly/txgSy
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 32 ms, faster than 92.86% of C++ online submissions
 * Memory Usage: 8.48 MB, less than 100.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 1e4+10, MOD = 1e9+7;

ll fac[MX] = {1};

ll quickPow(ll x, ll y) {
    if (y == 0) return 1ll;
    ll t = quickPow(x, y / 2) % MOD;
    return y % 2 == 0 ? t * t % MOD : t * t % MOD * x % MOD;
}

ll comb(ll x, ll y) {
    if (y == x || y == 0) return 1;
    ll a = fac[x];
    ll b = fac[y], c = fac[x - y];
    ll inv = quickPow(b * c % MOD, MOD - 2);
    return a * inv % MOD;
}

class Solution {
public:
    int countGoodSubsequences(string s) {
        int cnt[26] = {0}, mx = 0;

        ll res = 0;
        for (auto &c: s) {
            cnt[c - 'a']++;
            mx = max(mx, cnt[c - 'a']);
        }
        For(i,1,mx) fac[i] = fac[i - 1] * i % MOD;
        For(i,1,mx) {
            ll t = 1;
            For(j,0,25) {
                if (cnt[j] >= i) {
                    t = t * (comb(cnt[j], i) + 1) % MOD;
                }
            }
            res = (res + t - 1) % MOD;
        }
        return res;
    }
};