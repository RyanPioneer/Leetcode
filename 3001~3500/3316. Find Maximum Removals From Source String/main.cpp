/**
 * Source: is.gd/LGhoCB
 * Date: 2025/1/22
 * Skill:
 * Ref: 
 * Runtime: 1821 ms, faster than 21.85% of C++ online submissions
 * Memory Usage: 69.19 MB, less than 62.61% of C++ online submissions
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

#define ll long long
const int MX = 3e3+10;


class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int dp[MX][MX], n = source.size(), m = pattern.size();
        fill(&dp[0][0], &dp[0][0] + MX * MX, -2);
        unordered_set<int> st(targetIndices.begin(), targetIndices.end());

        function<int(int, int)> dfs = [&](int i, int j) {
            if (i == n) {
                return j == m ? 0 : INT32_MIN/8;
            }
            if (j == m) {
                return dfs(i+1, j) + (st.find(i) != st.end() ? 1 : 0);
            }
            if (dp[i][j] != -2) {
                return dp[i][j];
            }
            if (source[i] == pattern[j]) {
                dp[i][j] = dfs(i+1, j+1);
                dp[i][j] = max(dp[i][j], dfs(i+1, j) + (st.find(i) != st.end() ? 1 : 0));
            } else {
                dp[i][j] = dfs(i+1, j) + (st.find(i) != st.end() ? 1 : 0);
            }
            return dp[i][j];
        };

        return dfs(0, 0);
    }
};
