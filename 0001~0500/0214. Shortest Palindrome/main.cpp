/**
 * Source: https://rb.gy/b3ong
 * Date: 2023/9/14
 * Skill:
 * Runtime: WA
 * Memory Usage:
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    string shortestPalindrome(string s) {
        ll sz = s.length(), right = sz / 2 + sz % 2;
        ll hash1 = 0, hash2 = 0, base = 26, power_of_len = sz / 2 - 1, mod = 1e9+1;
        vector<ll> power(sz, 1);
        for (int i = 1; i < sz; i++)
            power[i] = power[i - 1] * base % mod;
        for (int i = sz / 2 + sz % 2; i < sz; i++)
            hash2 = (hash2 * base % mod + (s[i] - 'a')) % mod;
        for (int i = sz / 2 - 1; i >= 0; i--)
            hash1 = (hash1 * base % mod + (s[i] - 'a')) % mod;
        while (hash1 != hash2 && power_of_len >= 0) {
            if (sz % 2 == 0) {
                hash1 %= power[power_of_len];
                power_of_len--;
                hash2 /= base;
            } else {
                right--;
                hash2 = hash2 / base + (s[right] - 'a') * power[power_of_len] % mod;
            }
            sz++;
        }
        ll len = sz - s.length(), pos = s.length() - len;
        for (int i = 0; i < len; i++) {
            s = s[pos] + s;
            pos += 2;
        }
        return s;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}