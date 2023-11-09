/**
 * Source: t.ly/qnlTb
 * Date: 2023/11/7
 * Skill:
 * Runtime: 574 ms, faster than 37.50% of C++ online submissions
 * Memory Usage: 462.80 MB, less than 43.13% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= text.length <= 2000
 */


#define ll long long

const int MX = 2001;

class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int sz = text.length(), dp[MX][MX] = {0};
        unordered_set<string> res;
        for (int i = 1; i + 1 <= sz; i++) {
            for (int j = i + 1; j <= sz; j++) {
                if (text[i - 1] == text[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (dp[i][j] >= j - i) {
                        res.insert(text.substr(i, j - i));
                    }
                }
            }
        }
        return res.size();
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}