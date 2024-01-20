/**
 * Source: jpeg.ly/snF7A
 * Date: 2024/1/20
 * Skill:
 * Ref:
 * Runtime: 289 ms, faster than 5.01% of C++ online submissions
 * Memory Usage: 11.33 MB, less than 16.00% of C++ online submissions
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
const int MX = 65;


class Solution {
    ll memo[MX][MX][2];
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
        fill(memo[0][0], memo[64][64] + 2, -1);
        function<ll(int, int, bool)> dfs = [&](int idx, int cnt, bool is_equal) {
            if (idx < 0) return (ll)cnt;
            if (memo[idx][cnt][is_equal] != -1) return memo[idx][cnt][is_equal];
            ll count = 0;
            int up = is_equal ? num >> idx & 1 : 1;
            for (int i = 0; i <= up; i++) {
                count += dfs(idx - 1, cnt + (i == 1 && (idx + 1) % x == 0), is_equal && i == up);
            }
            return memo[idx][cnt][is_equal] = count;
        };
        int left_most_bit = 64 - __builtin_clzll(num);
        return dfs(left_most_bit - 1, 0, true) <= k;
    }
};