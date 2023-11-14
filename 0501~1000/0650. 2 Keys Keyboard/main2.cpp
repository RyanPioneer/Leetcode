/**
 * Source: t.ly/fTO1h
 * Date: 2023/11/14
 * Skill:
 * Runtime: 3 ms, faster than 70.86% of C++ online submissions
 * Memory Usage: 6.27 MB, less than 90.02% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 1000
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


const int MX = 1001;


class Solution {
public:
    int minSteps(int n) {
        int dp[MX] = {0};
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= i; j++) {
                if (i % j == 0) {
                    dp[i] = dp[i / j] + j;
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main() {
    Solution s;
}