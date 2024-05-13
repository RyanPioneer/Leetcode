/**
 * Source: ibit.ly/KDCdK
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 96 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.35 MB, less than 88.89% of C++ online submissions
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


const int MX = 1e3 + 10;

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int dp[MX], len = s.length();
        fill(dp, dp + MX, INT32_MAX);
        dp[0] = 0;
        for (int i = 1; i <= len; i++) {
            int cnt[26] = {0};
            for (int j = i; j > 0; j--) {
                cnt[s[j - 1] - 'a']++;
                int num = 0;
                bool check = true;
                for (int k = 0; k < 26; k++) {
                    if (cnt[k] != 0) {
                        if (num == 0 || num == cnt[k]) {
                            num = cnt[k];
                        } else {
                            check = false;
                            break;
                        }
                    }
                }
                if (check && dp[j - 1] != INT32_MAX) {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[len];
    }
};