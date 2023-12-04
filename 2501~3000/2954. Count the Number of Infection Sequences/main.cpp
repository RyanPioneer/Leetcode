/**
 * Source: jpeg.ly/PanRz
 * Date: 2023/12/4
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 34.90 MB, less than 100.00% of C++ online submissions
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
#define ll long long
ll mod = 1e9+7;
const int MX = 1e5;


ll quick_pow(ll x, int n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

ll fac[MX], inv_fac[MX];

auto init = []() {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) fac[i] = fac[i - 1] * i % mod;
    inv_fac[MX - 1] = quick_pow(fac[MX - 1], mod - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % mod;
    }
    return 0;
}();

ll comb(int n, int k) {
    return fac[n] * inv_fac[n - k] % mod * inv_fac[k] % mod;
}

class Solution {
public:
    int numberOfSequence(int n, vector<int>& sick) {
        int total = n - SZ(sick), k = 0;
        ll res = comb(total, sick[0]) * comb(total - sick[0], n - sick.back() - 1) % mod;
        total -= sick[0] + (n - sick.back() - 1);
        for (int i = 0; i + 1 < SZ(sick); i++) {
            int space = sick[i + 1] - sick[i] - 1;
            if (space == 0) continue;
            k += space - 1;
            res = res * comb(total, space) % mod;
            total -= space;
        }
        return res * quick_pow(2, k) % mod;
    }
};