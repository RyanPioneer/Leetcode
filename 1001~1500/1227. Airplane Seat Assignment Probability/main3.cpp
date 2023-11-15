/**
 * Source: ibit.ly/iQO1q
 * Date: 2023/11/15
 * Skill:
 * Runtime: 26 ms, faster than 5.14% of C++ online submissions
 * Memory Usage: 7.26 MB, less than 8.95% of C++ online submissions
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

const int MX = 1e5+1;

class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double dp[MX] = {0};
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = 1.0 / i + dp[i - 1] * (i - 2) / i;
        }
        return dp[n];
    }
};


int main() {
    Solution s;
}