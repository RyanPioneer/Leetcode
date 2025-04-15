/**
 * Source: t.ly/HJu-2
 * Date: 2025/4/15
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 95.26% of C++ online submissions
 * Memory Usage: 11.12 MB, less than 82.76% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= s.length <= 2000
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

#define ull unsigned long long

class Solution {
   public:
    int longestRepeatingSubstring(string s) {
        auto check = [&](int len) {
            unordered_set<ull> seen;
            ull num = 0, base = 26, power = 1;
            for (int i = 0; i < len; i++) {
                num = num * base + (s[i] - 'a');
                power *= base;
            }
            seen.insert(num);
            for (int i = len; i < s.size(); i++) {
                num = num * base - (s[i - len] - 'a') * power + (s[i] - 'a');
                if (seen.count(num)) return true;
                seen.insert(num);
            }
            return false;
        };

        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
