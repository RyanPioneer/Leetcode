/**
 * Source: t.ly/TVIQa
 * Date: 2023/9/24
 * Skill:
 * Runtime: 7 ms, faster than 60.35% of C++ online submissions
 * Memory Usage: 43.28 MB, less than 10.86% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= poured <= 10 ** 9
 *      0 <= query_glass <= query_row < 100
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
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(100, vector<double>(100, 0));
        dp[0][0] = poured;
        for (int i = 1; i < 100; i++) {
            bool flag = true;
            for (int j = 0; j < i; j++) {
                if (dp[i - 1][j] > 1) {
                    flag = false;
                    dp[i][j] += (dp[i - 1][j] - 1) / 2;
                    dp[i][j + 1] += (dp[i - 1][j] - 1) / 2;
                    dp[i - 1][j] = 1;
                }
            }
            if (flag || query_row == i - 1)
                break;
        }
        return dp[query_row][query_glass];
    }
};



int main() {
    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}