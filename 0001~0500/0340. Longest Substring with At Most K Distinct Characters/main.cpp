/**
 * Source: tinyurl.com/go6w3ax
 * Date: 2025/4/8
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 86.18% of C++ online submissions
 * Memory Usage: 9.67 MB, less than 80.40% of C++ online submissions
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
    int lengthOfLongestSubstringKDistinct(string s, int k)
    {
        int res = 0, diff = 0;
        unordered_map<char, int> cnt;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            if (cnt[s[r] - 'a']++ == 0) {
                ++diff;
            }
            while (diff > k) {
                if (--cnt[s[l] - 'a'] == 0) {
                    --diff;
                }
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
