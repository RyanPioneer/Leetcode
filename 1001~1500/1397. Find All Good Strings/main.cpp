/**
 * Source: jpeg.ly/l_guZ
 * Date: 2023/12/22
 * Skill: KMP
 * Ref:
 * Runtime: 21 ms, faster than 47.22% of C++ online submissions
 * Memory Usage: 7.55 MB, less than 20.83% of C++ online submissions
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
const int MX = 501;
ll mod = 1e9+7;


class Solution {
    ll dp[MX][51][2][2] = {0};
    vector<int> lps;
    int len;
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        lps = computeLPS(evil);
        len = evil.length();
        return dfs(0, n, s1, s2, evil, true, true, 0);
    }
    ll dfs(int idx, int n, string &s1, string &s2, string &evil, bool is_prefix_s1, bool is_prefix_s2,
           int evil_match) {
        if (evil_match == len) return 0;
        if (idx == n) return 1;
        if (dp[idx][evil_match][is_prefix_s1][is_prefix_s2]) return dp[idx][evil_match][is_prefix_s1][is_prefix_s2];
        char start = is_prefix_s1 ? s1[idx] : 'a';
        char end = is_prefix_s2 ? s2[idx] : 'z';
        ll res = 0;
        for (char i = start; i <= end; i++) {
            int pos = evil_match;
            while (pos > 0 && i != evil[pos]) pos = lps[pos - 1];
            if (i == evil[pos]) pos++;
            res = (res + dfs(idx + 1, n, s1, s2, evil, is_prefix_s1 && i == s1[idx], is_prefix_s2 && i == s2[idx], pos)) % mod;
        }
        return dp[idx][evil_match][is_prefix_s1][is_prefix_s2] = res;
    }
    vector<int> computeLPS(string s) {    // longest prefix also suffix
        vector<int> lps(s.length(), 0);
        for (int i = 1, j = 0; i < s.length(); i++) {
            while (j > 0 && s[i] != s[j]) j = lps[j - 1];
            if (s[i] == s[j]) lps[i] = ++j;
        }
        return lps;
    };
};