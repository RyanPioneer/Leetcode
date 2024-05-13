/**
 * Source: ibit.ly/Ol3bC
 * Date: 2024/5/12
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.88 MB, less than 80.00% of C++ online submissions
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
    int findPermutationDifference(string s, string t) {
        int pos1[26] = {0}, pos2[26] = {0}, n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            pos1[s[i] - 'a'] = i;
            pos2[t[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++) {
            res += abs(pos1[i] - pos2[i]);
        }
        return res;
    }
};