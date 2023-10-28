/**
 * Source: https://rb.gy/hfkz8
 * Date: 2023/10/28
 * Skill:
 * Runtime: 34 ms, faster than 91.98% of C++ online submissions
 * Memory Usage: 11.72 MB, less than 91.98% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define ll long long

const int MX = 1e5+1;

class Solution {
    ll mod = 1e9+7;
public:
    int countAnagrams(string s) {
        ll res = 1, fac[MX] = {1};
        for (int i = 1; i < MX; i++) fac[i] = fac[i - 1] * i % mod;
        int len = s.length(), cnt[26];
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < 26; j++) cnt[j] = 0;
            int num = 0;
            while (i < len && s[i] != ' ') {
                cnt[s[i++] - 'a']++;
                num++;
            }
            ll res1 = fac[num];
            for (int j = 0; j < 26; j++) {
                if (cnt[j] > 1) {
                    res1 = res1 * inv(fac[cnt[j]]) % mod;
                }
            }
            res = res * (res1 % mod) % mod;
        }
        return res;
    }
    ll inv(int x) {
        ll s = 1;
        for (; x > 1; x = mod % x) s = s * (mod - mod / x) % mod;
        return s;
    }
};

int main() {
    Solution s;
}