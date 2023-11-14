/**
 * Source: t.ly/Bf7Aj
 * Date: 2023/11/14
 * Skill:
 * Runtime: 18 ms, faster than 96.09% of C++ online submissions
 * Memory Usage: 6.26 MB, less than 99.22% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 1000
 *      1 <= k <= n-1
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

const int MX = 1001;


class Solution {
public:
    int numberOfSets(int n, int k) {
        ll mod = 1e9+7, dp[MX] = {0}, dp2[MX] = {0}, total[MX] = {0};
        total[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                dp2[j] = dp[j];
                dp[j] = (total[j - 1] + dp2[j]) % mod;
                total[j] = (total[j] + dp[j]) % mod;
            }
        }
        return total[k] % mod;
    }
};


int main() {
    Solution s;
    int res = s.numberOfSets(4, 2);
}