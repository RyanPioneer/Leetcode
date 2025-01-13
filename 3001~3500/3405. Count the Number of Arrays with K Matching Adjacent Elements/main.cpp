/**
 * Source: ibit.ly/z1cEd
 * Date: 2025/1/12
 * Skill:
 * Ref:
 * Runtime: 91 ms, faster than 54.57% of C++ online submissions
 * Memory Usage: 123.71 MB, less than 28.76% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= n, m <= 10 ** 5
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <cmath>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

#define ll long long
const int MOD = 1e9 + 7;


class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        vector<ll> factorial = getFactorial(n);
        return comb(n-1, k, factorial) * m % MOD * quickPow(m-1, n-1-k) % MOD; 
    }
    vector<ll> getFactorial(int n) {
        vector<ll> res(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            res[i] = res[i - 1] * i % MOD;
        }
        return res;
    }
    ll quickPow(ll x, ll n) {
        if (n == 0) return 1;
        if (n == 1) return x;
        ll res = quickPow(x, n / 2);
        res = res * res % MOD;
        if (n % 2) res = res * x % MOD;
        return res;
    }
    ll comb(ll n, ll m, vector<ll>& factorial) {
        return factorial[n] * quickPow(factorial[m], MOD - 2) % MOD * quickPow(factorial[n - m], MOD - 2) % MOD;
    }
};
