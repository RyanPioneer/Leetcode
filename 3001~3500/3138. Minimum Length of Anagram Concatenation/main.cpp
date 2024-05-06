/**
 * Source: t.ly/Un3bx
 * Date: 2024/5/5
 * Skill:
 * Ref:
 * Runtime: 18 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 12.19 MB, less than 100.00% of C++ online submissions
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


class Solution {
public:
    int minAnagramLength(string s) {
        int cnt[26];
        for (auto &c: s) {
            cnt[c - 'a']++;
        }
        for (int part = s.length(); part > 1; part--) {
            bool check = true;
            for (int j = 0; j < 26; j++) {
                if (cnt[j] % part != 0) {
                    check = false;
                    break;
                }
            }
            if (check) return s.length() / part;
        }
        return s.length();
    }
};