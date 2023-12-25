/**
 * Source: is.gd/RQ0205
 * Date: 2023/12/25
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.35 MB, less than 98.44% of C++ online submissions
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
const int MX = 101;


class Solution {
public:
    int numDecodings(string s) {
        int dp[MX] = {0};
        dp[0] = 1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '0') dp[i + 1] = dp[i];
            if (i > 0 && s[i - 1] != '0' && 10 * (s[i - 1] - '0') + s[i] - '0' <= 26) dp[i + 1] += dp[i - 1];
        }
        return dp[s.length()];
    }
};