/**
 * Source: jpeg.ly/rpJ61
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 78.15% of C++ online submissions
 * Memory Usage: 6.30 MB, less than 93.77% of C++ online submissions
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
const int MX = 17;


class Solution {
    ll dp[2][2][MX];
    string start, finish;
    int n, n2, limit;
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        fill(dp[0][0], dp[1][1] + MX, -1);
        this->start = to_string(start);
        this->finish = to_string(finish);
        n = this->finish.length();
        n2 = s.length();
        this->start = string(this->finish.length() - this->start.length(), '0') + this->start;
        this->limit = limit;
        return dfs(0, true, true, s);
    }
    ll dfs(int idx, bool lower, bool upper, string &s) {
        if (dp[lower][upper][idx] != -1) return dp[lower][upper][idx];
        if (idx == n) return 1;
        int lo = lower ? this->start[idx] - '0' : 0;
        int hi = upper ? this->finish[idx] - '0' : 9;
        ll res = 0;
        if (idx >= n - n2) {
            int d = s[n2 - (n - idx)] - '0';
            if (lo <= d && d <= hi) res += dfs(idx + 1, lower && d == this->start[idx] - '0', upper && d == this->finish[idx] - '0', s);
        } else {
            for (int i = lo; i <= min(hi, this->limit); i++) {
                res += dfs(idx + 1, lower && i == this->start[idx] - '0', upper && i == this->finish[idx] - '0', s);
            }
        }
        dp[lower][upper][idx] = res;
        return res;
    }
};