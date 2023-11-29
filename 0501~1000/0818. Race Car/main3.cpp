/**
 * Source: is.gd/fL4PzO
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 75.58% of C++ online submissions
 * Memory Usage: 6.68 MB, less than 91.47% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
typedef pair<int, int> PII;
const int MX = 1e4 + 1;


class Solution {
public:
    int racecar(int target) {
        int max_bit = 32 - __builtin_clz(target);
        vector<int> dp(1 << max_bit, INT32_MAX);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= target; i++) {
            int bit_len = 32 - __builtin_clz(i);
            if (i == (1 << bit_len) - 1) {
                dp[i] = bit_len;
                continue;
            }
            int num = 1 << (bit_len - 1);
            for (int j = 0; j < bit_len; j++) {
                dp[i] = min(dp[i], dp[i - num + (1 << j)] + bit_len - 1 + j + 2);
            }
            dp[i] = min(dp[i], dp[num * 2 - 1 - i] + bit_len + 1);
        }
        return dp[target];
    }
};