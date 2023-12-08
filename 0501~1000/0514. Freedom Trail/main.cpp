/**
 * Source: is.gd/hK7A7K
 * Date: 2023/12/8
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 6.71 MB, less than 96.54% of C++ online submissions
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


const int MX = 100;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int dp[MX] = {0}, dp2[MX] = {0}, len = ring.length(), res = INT32_MAX;
        for (int i = 0; i < len; i++) {
            if (ring[i] == key[0]) dp[i] = min(i, len - i) + 1;
            else dp[i] = INT32_MAX / 2;
        }
        for (int i = 1; i < key.length(); i++) {
            for (int j = 0; j < len; j++) {
                dp2[j] = dp[j];
                dp[j] = INT32_MAX / 2;
            }
            for (int j = 0; j < len; j++) {
                if (ring[j] == key[i]) {
                    for (int k = 0; k < len; k++) {
                        if (ring[k] == key[i - 1]) {
                            int a = max(j, k), b = min(j, k);
                            int l = min(a - b, b + len - a);
                            dp[j] = min(dp[j], dp2[k] + l + 1);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < len; i++) res = min(res, dp[i]);
        return res;
    }
};