/** 
 * Source: https://leetcode.com/problems/get-equal-substrings-within-budget/
 * Date: 2021/7/13
 * Skill: Sliding Window
 * Constraints: 
 *      1 <= s.length, t.length <= 10^5
 *      0 <= maxCost <= 10^6
 *      s and t only contain lower case English letters.
 */

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

int equalSubstring(string s, string t, int k) {
        int n = s.length(), i = 0, j;
        for (j = 0; j < n; ++j) {
            if ((k -= abs(s[j] - t[j])) < 0)
                k += abs(s[i] - t[i++]);
        }
        return j - i;
}