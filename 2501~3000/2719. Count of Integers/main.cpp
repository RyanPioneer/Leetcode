/**
 * Source: t.ly/IYLAV
 * Date: 2023/11/10
 * Skill:
 * Runtime: 42 ms, faster than 35.02% of C++ online submissions
 * Memory Usage: 6.55 MB, less than 66.61% of C++ online submissions
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

typedef pair<int, int> pairs;

const int MX = 21;


class Solution {
    ll mod = 1e9+7;
    ll dp[2][25][401] = {0};
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        min_sum -= 1;
        int n1 = 0, n2 = 0, len1 = num1.length(), len2 = num2.length(), l1 = 0, l2 = 0, count = 0;
        for (auto c: num1) count += c - '0';
        ll res1 = dfs(num2, max_sum, n1, false, len2, l1) % mod;
        memset(dp, 0, sizeof(dp));
        ll res2 = dfs(num2, min_sum, n2, false, len2, l2) % mod;
        memset(dp, 0, sizeof(dp));
        n1 = 0, n2 = 0, l1 = 0, l2 = 0;
        ll res3 = dfs(num1, max_sum, n1, false, len1, l1) % mod;
        memset(dp, 0, sizeof(dp));
        ll res4 = dfs(num1, min_sum, n2, false, len1, l2) % mod;
        return (res1 - res2 + mod - (res3 - res4 + mod) % mod + mod + (count <= max_sum && count > min_sum)) % mod;
    }
    ll dfs(string &mx, int &max_sum, int &cur_sum, bool is_smaller_before, int &mx_len, int &cur_len) {
        if (cur_len == mx_len) return 1;
        if (dp[is_smaller_before][cur_len][cur_sum] > 0) return dp[is_smaller_before][cur_len][cur_sum];
        ll res = 0;
        for (int i = 0; i < 10; i++) {
            if (cur_sum + i > max_sum) break;
            if (!is_smaller_before && i > mx[cur_len] - '0') break;
            cur_sum += i;
            cur_len += 1;
            if (!is_smaller_before && i == mx[cur_len - 1] - '0') {
                res = (res + dfs(mx, max_sum, cur_sum, is_smaller_before, mx_len, cur_len)) % mod;
            } else {
                res = (res + dfs(mx, max_sum, cur_sum, true, mx_len, cur_len)) % mod;
            }
            cur_sum -= i;
            cur_len -= 1;
        }
        dp[is_smaller_before][cur_len][cur_sum] = res;
        return res;
    }
};


int main() {
    Solution s;
}