/**
 * Source: t.ly/CmuHj
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.89 MB, less than 88.69% of C++ online submissions
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

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k)
    {
        int cnt[26] = { 0 }, res = 0, rep = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i >= k) {
                cnt[s[i - k] - 'a']--;
                if (cnt[s[i - k] - 'a'] == 1) {
                    rep--;
                }
            }
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 2) {
                rep++;
            }
            if (i >= k - 1 && rep == 0) {
                res++;
            }
        }
        return res;
    }
};
