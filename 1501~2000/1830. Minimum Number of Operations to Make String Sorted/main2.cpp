/**
 * Source: ibit.ly/U-WBe
 * Date: 2023/11/17
 * Skill:
 * Runtime: 169 ms, faster than 25.81% of C++ online submissions
 * Memory Usage: 7.16 MB, less than 100.00% of C++ online submissions
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


const int MX = 3001;

#define ll long long

ll mod = 1e9+7;
ll inv(int x) {
    ll s = 1;
    for (; x > 1; x = mod % x) s = s * (mod - mod / x) % mod;
    return s;
}

class Solution {
public:
    int makeStringSorted(string s) {
        ll res = 0, fac[MX] = {1};
        int freq[26] = {0}, len = s.length();
        for (int i = 1; i <= len; i++) fac[i] = fac[i - 1] * i % mod;
        for (auto &c: s) freq[c - 'a']++;
        for (int i = 0; i < len; i++) {
            ll cur = s[i] - 'a', num = 0;
            for (int j = 0; j < cur; j++) num += freq[j];
            num = num * fac[len - i - 1] % mod;
            for (int j = 0; j < 26; j++) num = num * inv(fac[freq[j]]) % mod;
            res = (res + num) % mod;
            freq[cur]--;
        }
        return res;
    }
};


int main() {
    Solution s;
}