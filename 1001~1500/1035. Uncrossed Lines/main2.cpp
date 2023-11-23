/**
 * Source: is.gd/klqugv
 * Date: 2023/11/23
 * Skill: Longest common subsequence, dp[i][j]: nums1[:i+1], nums2[:j+1] 之 LCS
 * Ref:
 * Runtime: 8 ms, faster than 89.73% of C++ online submissions
 * Memory Usage: 11.04 MB, less than 81.61% of C++ online submissions
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
const int MX = 500 + 1;


class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int len1 = SZ(nums1), len2 = SZ(nums2), dp[MX][MX] = {0};
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                if (nums1[i] == nums2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[len1][len2];
    }
};