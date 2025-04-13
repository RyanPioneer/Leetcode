/**
 * Source: tinyurl.com/2xjbnzl3
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime: 499 ms, faster than 86.00% of C++ online submissions
 * Memory Usage: 186.22 MB, less than 86.00% of C++ online submissions
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
#define ull unsigned long long

class Solution {
   public:
    int countDistinct(string s) {
        int res = 0;
        for (int len = 1; len <= s.length(); len++) {
            ull power = 1;
            for (int i = 1; i <= len; i++) {
                power *= 26;
            }
            unordered_set<ull> st;
            ull hash = 0;
            for (int i = 0; i < len; i++) {
                hash = hash * 26 + (s[i] - 'a');
            }
            st.insert(hash);
            for (int i = len; i < s.length(); i++) {
                hash = hash * 26 + (s[i] - 'a') - power * (s[i - len] - 'a');
                st.insert(hash);
            }
            res += st.size();
        }
        return res;
    }
};
