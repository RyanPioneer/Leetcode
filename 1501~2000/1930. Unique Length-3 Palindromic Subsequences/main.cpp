/**
 * Source: t.ly/zR5cN
 * Date: 2023/11/14
 * Skill:
 * Runtime: 65 ms, faster than 94.29% of C++ online submissions
 * Memory Usage: 11.52 MB, less than 94.75% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      3 <= s.length <= 10 ** 5
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


const int MX = 26;


class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt[MX][MX] = {0}, left[MX], right[MX], len = s.length(), res = 0;
        for (int i = 0; i < MX; i++) {
            left[i] = len;
            right[i] = -1;
        }
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            for (int j = 0; j < MX; j++) {
                if (c == j) {
                    if (right[c] > left[c]) cnt[c][c] = 1;
                } else {
                    if (right[j] > left[c]) cnt[c][j] = 1;
                }
            }
            right[c] = i;
            left[c] = min(left[c], i);
        }
        for (int i = 0; i < MX; i++) {
            for (int j = 0; j < MX; j++) {
                res += cnt[i][j];
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}