/**
 * Source: twtr.to/z8cnM
 * Date: 2023/11/21
 * Skill: Two pointer
 * Ref: twtr.to/dKqYU
 * Runtime: 53 ms, faster than 71.63% of C++ online submissions
 * Memory Usage: 20.71 MB, less than 43.26% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
using namespace std;


class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, len = SZ(s);
        while (j < len) {
            int k = 0;
            while (j + k < len && s[i + k] == s[j + k]) k++;
            if (j + k == len || s[j + k] < s[i + k]) {
                j += k + 1;
            } else {
                int t = i;
                i = j;
                j = max(i + 1, t + k + 1);
            }
        }
        return s.substr(i);
    }
};