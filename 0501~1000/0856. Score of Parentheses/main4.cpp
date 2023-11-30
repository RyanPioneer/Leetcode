/**
 * Source: is.gd/1fOV69
 * Date: 2023/11/30
 * Skill: Divide and conquer
 * Ref:
 * Runtime: 2 ms, faster than 50.85% of C++ online submissions
 * Memory Usage: 6.29 MB, less than 99.60% of C++ online submissions
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
    int scoreOfParentheses(string s) {
        int depth = 0, res = 0;
        char prev = ' ';
        for (auto &c: s) {
            depth += c == '(' ? 1 : -1;
            if (c == ')' && prev == '(') res += 1 << depth;
            prev = c;
        }
        return res;
    }
};