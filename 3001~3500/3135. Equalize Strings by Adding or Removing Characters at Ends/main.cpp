/**
 * Source: ibit.ly/7fN0I
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 171 ms, faster than 60.55% of C++ online submissions
 * Memory Usage: 14.29 MB, less than 55.05% of C++ online submissions
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

const int MX = 1e3+10;


class Solution {
public:
    int minOperations(string initial, string target) {
        int dp[MX][MX] = {0}, res = 0;
        int len1 = initial.length(), len2 = target.length();
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                if (initial[i] == target[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return (len1 - res) + (len2 - res);
    }
};