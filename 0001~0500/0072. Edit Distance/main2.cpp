/** 
 * Source: https://leetcode.com/problems/edit-distance/
 * Date: 2021/7/16
 * Skill: DP
 * Runtime: 8 ms
 * Time complexity: O(n*m)
 * Space complexity: O(n)
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
        int m = word1.size(), n = word2.size(), pre;
        vector<int> cur(n + 1, 0);
        for (int j = 1; j <= n; j++) 
            cur[j] = j;
        for (int i = 1; i <= m; i++) {
            pre = cur[0];
            cur[0] = i;
            for (int j = 1; j <= n; j++) {
                int temp = cur[j];
                if (word1[i - 1] == word2[j - 1]) {
                    cur[j] = pre;
                } else {
                    cur[j] = min(pre, min(cur[j - 1], cur[j])) + 1;
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};
static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();