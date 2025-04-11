/**
 * Source: t.ly/l0B0t
 * Date: 2025/4/10
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 88.41% of C++ online submissions
 * Memory Usage: 12.11 MB, less than 81.31% of C++ online submissions
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
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int res = 0, left = 0, diff = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < s.size(); right++) {
            if (cnt[s[right]]++ == 0) diff++;
            while (diff > 2) {
                if (--cnt[s[left]] == 0) diff--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
