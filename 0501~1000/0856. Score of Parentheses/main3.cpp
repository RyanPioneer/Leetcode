/**
 * Source: is.gd/1fOV69
 * Date: 2023/11/30
 * Skill: Divide and conquer
 * Ref:
 * Runtime: 3 ms, faster than 19.06% of C++ online submissions
 * Memory Usage: 7.00 MB, less than 6.82% of C++ online submissions
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
        if (s.length() == 2) return 1;
        int cnt = 0, len;
        for (int i = 0; i < s.length(); i++) {
            cnt += s[i] == '(' ? 1 : -1;
            if (cnt == 0) {
                len = i + 1;
                break;
            }
        }
        if (len < s.length()) {
            return scoreOfParentheses(s.substr(0, len)) + scoreOfParentheses(s.substr(len, s.length() - len));
        } else {
            return scoreOfParentheses(s.substr(1, len - 2)) * 2;
        }
    }
};