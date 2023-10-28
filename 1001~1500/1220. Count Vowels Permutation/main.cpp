/**
 * Source: tinyurl.com/yusdgsyd
 * Date: 2023/10/28
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.19 MB, less than 93.28% of C++ online submissions
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

class Solution {
public:
    int countVowelPermutation(int n) {
        ll mod = 1e9+7, res = 0;
        ll dp[5], dp2[5];
        for (int i = 0; i < 5; i++) dp[i] = 1;
        for (int i = 2; i <= n; i++) {
            for (int i = 0; i < 5; i++) dp2[i] = dp[i];
            dp[0] = (dp2[1] + dp2[2] + dp2[4]) % mod;
            dp[1] = (dp2[0] + dp2[2]) % mod;
            dp[2] = (dp2[1] + dp2[3]) % mod;
            dp[3] = dp2[2] % mod;
            dp[4] = (dp2[2] + dp2[3]) % mod;
        }
        for (int i = 0; i < 5; i++) res = (res + dp[i]) % mod;
        return res;
    }
};


int main() {
//    Solution s;
}