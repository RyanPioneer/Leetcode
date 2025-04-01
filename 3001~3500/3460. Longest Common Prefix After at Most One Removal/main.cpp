/**
 * Source: t.ly/JKGDN
 * Date: 2025/3/9
 * Skill:
 * Ref:
 * Runtime: 45 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 145.86 MB, less than 65.31% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long

class Solution {
public:
    int longestCommonPrefix(string s, string t)
    {
        int zero = s[0] == t[0] ? 1 : 0, one = 0;
        for (int i = 1; i < s.size(); i++) {
            if (one >= 0 && s[i - 1] == t[i]) {
            }
            zero = s[i] == t[i] ? zero + 1 : INT32_MIN / 2;
        }
    }
};
