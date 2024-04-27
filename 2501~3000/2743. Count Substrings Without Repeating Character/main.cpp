/**
 * Source: tinyurl.com/2byjsm3k
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 66 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 20.16 MB, less than 92.50% of C++ online submissions
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
    int numberOfSpecialSubstrings(string s) {
        int res = 0, n = s.length(), cnt[MX] = {0};

        for (int left = 0, right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;
            while (cnt[s[right] - 'a'] > 1) {
                cnt[s[left++] - 'a']--;
            }
            res += right - left + 1;
        }
        return res;
    }
};