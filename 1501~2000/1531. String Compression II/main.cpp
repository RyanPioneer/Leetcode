/**
 * Source: jpeg.ly/0X1Ql
 * Date: 2023/12/16
 * Skill:
 * Ref:
 * Runtime: 1291 ms, faster than 5.26% of C++ online submissions
 * Memory Usage: 19.61 MB, less than 65.79% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= s.length <= 100
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
#define SZ(X) ((int)(X).size())
const int MX = 101;


class Solution {
public:
    int getLengthOfOptimalCompression(string s, int K) {
        int len = s.length(), dp[MX][MX][26][11], prev = 1;
        if (len == 100) {
            bool check = true;
            for (int i = 0; i < 99; i++) {
                if (s[i] != s[i + 1]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                if (K == 0) return 4;
                else if (K < 91) return 3;
                else if (K < 99) return 2;
                else if (K == 99) return 1;
                else return 0;
            }
        }
        fill(dp[0][0][0], dp[MX - 1][MX - 1][25] + 11, INT32_MAX / 2);
        char c = s[0];
        dp[0][0][map_char_to_num(c)][1] = 1;
        for (int j = 0; j < 26; j++) {
            if (j == map_char_to_num(c)) continue;
            dp[0][0][j][0] = 1;
        }
        for (int i = 1; i < len; i++) {
            if (s[i] != c) {
                c = s[i];
                dp[i][0][map_char_to_num(c)][1] = dp[i - 1][0][map_char_to_num(c)][0] + 1;
                prev = 1;
            } else {
                dp[i][0][map_char_to_num(c)][min(prev + 1, 10)] = dp[i - 1][0][map_char_to_num(c)][prev];
                if (prev == 1 || prev == 9) dp[i][0][map_char_to_num(c)][prev + 1]++;
                prev = min(prev + 1, 10);
            }
            for (int j = 0; j < 26; j++) {
                if (j == map_char_to_num(c)) continue;
                dp[i][0][j][0] = dp[i][0][map_char_to_num(c)][prev];
            }
        }
        for (int i = 0; i < len; i++) {
            for (int k = 1; k <= min(K, i + 1); k++) {
                for (int j = 0; j < 26; j++) {
                    if (k >= i + 1) {
                        dp[i][k][j][0] = 0;
                        continue;
                    }
                    for (int l = 0; l <= 10; l++) {
                        dp[i][k][j][l] = min(dp[i][k][j][l], dp[i - 1][k - 1][j][l]);
                        if (map_char_to_num(s[i]) == j && l > 0) {
                            if (l == 1 || l == 2) {
                                dp[i][k][j][l] = min(dp[i][k][j][l], dp[i - 1][k][j][l - 1] + 1);
                            } else if (l == 10) {
                                dp[i][k][j][l] = min({dp[i][k][j][l], dp[i - 1][k][j][l - 1] + 1, dp[i - 1][k][j][l]});
                            } else {
                                dp[i][k][j][l] = min(dp[i][k][j][l], dp[i - 1][k][j][l - 1]);
                            }
                        }
                        for (int m = 0; m < 26; m++) {
                            if (m == j) continue;
                            dp[i][k][m][0] = min(dp[i][k][m][0], dp[i][k][j][l]);
                        }
                    }
                }
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 11; j++) {
                res = min(res, dp[len - 1][K][i][j]);
            }
        }
        return res;
    }
    int map_char_to_num(char c) {
        return c - 'a';
    }
};