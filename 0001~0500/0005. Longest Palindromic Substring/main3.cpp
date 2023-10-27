/**
 * Source: tinyurl.com/yu4qppns
 * Date: 2023/10/27
 * Skill:
 * Runtime: 110 ms, faster than 48.80% of C++ online submissions
 * Memory Usage: 11.57 MB, less than 57.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= s.length <= 1000
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

class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1001][1001], sz = s.length(), mx = 1, head = 0;
        for (int i = 0; i < sz - 1; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                mx = 2;
                head = i;
            } else {
                dp[i][i + 1] = 0;
            }
        }
        dp[sz - 1][sz - 1] = 1;
        for (int len = 3; len <= sz; len++) {
            int right = len - 1;
            for (int left = 0; left + len <= sz; left++, right++) {
                if (s[left] == s[right] && dp[left + 1][right - 1] == 1) {
                    dp[left][right] = 1;
                    if (len > mx) {
                        mx = len;
                        head = left;
                    }
                } else {
                    dp[left][right] = 0;
                }
            }
        }
        return s.substr(head, mx);
    }
};


int main() {
//    Solution s;
}