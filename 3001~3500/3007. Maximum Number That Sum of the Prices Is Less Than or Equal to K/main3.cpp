/**
 * Source: jpeg.ly/snF7A
 * Date: 2024/1/20
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 62.17% of C++ online submissions
 * Memory Usage: 7.98 MB, less than 16.51% of C++ online submissions
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


class Solution {
public:
    long long findMaximumNumber(long long k, int x) {
        ll lo = (1 << (x - 1)), hi = (1 << (x - 1)) * (k + 1);
        while (lo < hi) {
            ll mid = (lo + hi + 1) >> 1;
            if (check(mid, k, x)) lo = mid;
            else hi = mid - 1;
        }
        return lo;
    }
    bool check(ll num, ll k, int x) {
        ll cnt = 0;
        ll bit_num = 64 - __builtin_clzll(num);
        for (int i = x; i <= bit_num; i += x) {
            ll rep = 1ll << i;
            ll time = (num + 1) / rep, rem = (num + 1) % rep;
            cnt += time * (rep >> 1);
            cnt += max(0ll, rem - (rep >> 1));
        }
        return cnt <= k;
    }
};