/**
 * Source: is.gd/iH793j
 * Date: 2023/12/26
 * Skill:
 * Ref:
 * Runtime: 51 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 17.98 MB, less than 94.12% of C++ online submissions
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
const int MX = 26;


class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.length() != t.length()) return false;
        int cnt[MX] = {0};
        for (int i = 0; i < s.length(); i++) {
            char a = s[i], b = t[i];
            if (a <= b) cnt[b - a]++;
            else cnt[26 - (a - b)]++;
        }
        for (int i = 1; i < 26; i++) {
            if (cnt[i] > k / 26 + (k % 26 >= i)) return false;
        }
        return true;
    }
};