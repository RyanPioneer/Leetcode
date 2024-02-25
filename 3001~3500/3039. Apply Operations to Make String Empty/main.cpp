/**
 * Source: is.gd/uH3XP3
 * Date: 2024/2/24
 * Skill:
 * Ref:
 * Runtime: 103 ms, faster than 94.08% of C++ online submissions
 * Memory Usage: 30.26 MB, less than 98.45% of C++ online submissions
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

const int MX = 26;


class Solution {
public:
    string lastNonEmptyString(string s) {
        int cnt[MX] = {0}, mx = 0, len = s.length();
        for (auto &c: s) cnt[c - 'a']++;
        string res = "";
        for (int i = 0; i < MX; i++) mx = max(mx, cnt[i]);
        for (int i = len - 1; i >= 0; i--) {
            char c = s[i];
            if (cnt[c - 'a'] == mx) {
                res.push_back(c);
                cnt[c - 'a']--;
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};