/**
 * Source: ibit.ly/Vuxmx
 * Date: 2023/10/8
 * Skill:
 * Runtime: 6 ms, faster than 99.74% of C++ online submissions
 * Memory Usage: 10.35 MB, less than 87.92% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n][m];
        dp[0][0] = nums1[0] * nums2[0];
        for (int i = 1; i < m; i++)
            dp[0][i] = max(dp[0][i - 1], nums1[0] * nums2[i]);
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], nums1[i] * nums2[0]);
            for (int j = 1; j < m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = max(dp[i][j], nums1[i] * nums2[j]);
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + nums1[i] * nums2[j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}