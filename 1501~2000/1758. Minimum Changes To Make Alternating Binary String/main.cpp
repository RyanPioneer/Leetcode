/**
 * Source: is.gd/P24ca3
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 78.34% of C++ online submissions
 * Memory Usage: 7.28 MB, less than 86.65% of C++ online submissions
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
    int minOperations(string s) {
        return min(helper(s, 1), helper(s, 0));
    }
    int helper(string &s, int n) {
        int res = 0;
        for (auto &c: s) {
            if (c - '0' != n) res++;
            n = 1 - n;
        }
        return res;
    }
};