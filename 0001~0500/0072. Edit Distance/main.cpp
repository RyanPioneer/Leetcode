/** 
 * Source: https://leetcode.com/problems/edit-distance/
 * Date: 2021/7/16
 * Skill: DP
 * Runtime: 12 ms
 * Time complexity: O(max(n, m))
 * Space complexity: O(n*m)
 * Constraints: 
 *      0 <= word1.length, word2.length <= 500
 *      word1 and word2 consist of lowercase English letters.
 *      Insert a character
 *      Delete a character
 *      Replace a character
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        for (int i = 1; i <= word2.length(); i++) 
            dp[0][i] = i;
        for (int i = 1; i <= word1.length(); i++) 
            dp[i][0] = i;
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
            }
        }
        return dp[word1.length()][word2.length()];
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();