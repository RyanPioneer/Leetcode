/**
 * Source: twtr.to/B3DJR
 * Date: 2023/11/18
 * Skill:
 * Runtime: 4 ms, faster than 58.22% of C++ online submissions
 * Memory Usage: 6.49 MB, less than 100.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
#include <functional>
#include <list>


using namespace std;

#define ll long long

const int MX = 1001;


class Solution {
public:
    int longestDecomposition(string text) {
        ll mod = 1e9+7, power[MX] = {1}, p = 27;
        for (int i = 1; i < MX; i++) power[i] = power[i - 1] * p % mod;
        int dp[MX] = {0}, sz = text.length(), res = 1;
        for (int i = 0; i < sz / 2; i++) {
            int a = i, b = sz - 1 - i;
            ll hash1 = 0;
            ll hash2 = 0, cur_pow = 1;
            while (a >= 0) {
                hash1 = (hash1 + (text[a] - 'a' + 1) * cur_pow) % mod;
                cur_pow = cur_pow * p % mod;
                hash2 = (hash2 * p + (text[b] - 'a' + 1)) % mod;
                if (hash1 == hash2 && (dp[a] > 0 || a == 0)) {
                    dp[i + 1] = max(dp[i + 1], dp[a] + 1);
                    break;
                }
                a--;
                b++;
            }
            res = max(res, dp[i + 1] * 2 + ((i + 1) * 2 == sz ? 0 : 1));
        }
        return res;
    }
};