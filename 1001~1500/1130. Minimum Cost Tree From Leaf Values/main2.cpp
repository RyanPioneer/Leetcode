/**
 * Source: twtr.to/AMqh6
 * Date: 2023/11/21
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.57 MB, less than 94.24% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
const int MX = 40;


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = SZ(arr), dp[MX][MX], largest[MX][MX];
        for (int i = 0; i < n; i++) largest[i][i] = arr[i];
        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len <= n; left++) {
                int right = left + len - 1;
                largest[left][right] = max(largest[left][left], largest[left + 1][right]);
            }
        }
        for (int len = 2; len <= n; len++) {
            for (int left = 0; left + len <= n; left++) {
                int right = left + len - 1;
                dp[left][right] = INT32_MAX;
                for (int mid = left; mid < right; mid++) {
                    dp[left][right] = min(dp[left][right], dp[left][mid] + dp[mid + 1][right] + largest[left][mid] * largest[mid + 1][right]);
                }
            }
        }
        return dp[0][n - 1];
    }
};