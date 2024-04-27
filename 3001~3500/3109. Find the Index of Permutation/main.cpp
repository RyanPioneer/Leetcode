/**
 * Source: t.ly/18NaF
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 188 ms, faster than 59.42% of C++ online submissions
 * Memory Usage: 353.34 MB, less than 5.80% of C++ online submissions
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

const int MX = 1e5+10, MOD = 1e9+7;

class BIT {
public:
    int arr[MX] = {0};

    int query(int idx) {
        int num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }
};


class Solution {
public:
    int getPermutationIndex(vector<int>& perm) {
        BIT *tree = new BIT();
        ll res = 0, n = perm.size();
        vector<ll> fac(n + 1, 1);

        for (int i = 2; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
        for (int i = 1; i <= n; i++) tree->update(i, 1);
        for (int i = 1; i <= n; i++) {
            res = (res + fac[n - i] * tree->query(perm[i - 1] - 1) % MOD) % MOD;
            tree->update(perm[i - 1], -1);
        }
        return res;
    }
};