/**
 * Source: t.ly/Phs4_
 * Date: 2023/9/26
 * Skill:
 * Runtime: 208 ms, faster than 48.00% of C++ online submissions
 * Memory Usage: 85.19 MB, less than 26.68% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
    ll mod = 1e9+7;
public:
    int numberOfWays(string s, string t, long long k) {
        string ss = s + s;
        ss.pop_back();
        int num = find_target(ss, t), n = s.length();
        vector<ll> transport_matrix{num - 1, n - num, num, n - num - 1};
        vector<ll> res = quick_mul(transport_matrix, k);
        if (s == t)
            return res[0];
        else
            return res[2];
    }
    vector<ll> mat_mul(vector<ll> mat1, vector<ll> mat2) {
        ll num1 = (mat1[0] * mat2[0] % mod + mat1[2] * mat2[1] % mod) % mod;
        ll num2 = (mat1[1] * mat2[0] % mod + mat1[3] * mat2[1] % mod) % mod;
        ll num3 = (mat1[0] * mat2[2] % mod + mat1[2] * mat2[3] % mod) % mod;
        ll num4 = (mat1[1] * mat2[2] % mod + mat1[3] * mat2[3] % mod) % mod;
        return {num1, num2, num3, num4};
    }
    vector<ll> quick_mul(vector<ll> mat, ll t) {
        if (t == 0)
            return {1, 0, 0, 1};
        if (t == 1)
            return mat;
        vector<ll> mat2 = mat_mul(mat, mat);
        vector<ll> mat3 = quick_mul(mat2, t / 2);
        if (t % 2 == 0)
            return mat3;
        else
            return mat_mul(mat3, mat);
    }
    int find_target(string s, string t) {
        int res = 0, sz = t.length();
        vector<int> suf = preprocessing(t);
        vector<int> dp(s.length(), 0);
        dp[0] = (s[0] == t[0]);
        if (sz == 1 && dp[0] == 1)
            res++;
        for (int i = 1; i < s.length(); i++) {
            int j = dp[i - 1];
            while (j > 0 && s[i] != t[j])
                j = suf[j - 1];
            dp[i] = j + (s[i] == t[j]);
            if (dp[i] == sz)
                res++;
        }
        return res;
    }
    vector<int> preprocessing(string s) {
        vector<int> dp(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            int j = dp[i - 1];
            while (j > 0 && s[i] != s[j])
                j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        return dp;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}