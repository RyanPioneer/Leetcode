/**
 * Source: is.gd/1fOV69
 * Date: 2023/11/30
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.63 MB, less than 14.74% of C++ online submissions
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
        stack<int> st;
        int num = 0;
        for (auto &c: s) {
            if (c == ')') {
                num = num == 0 ? 1 : num * 2;
                num += st.top();
                st.pop();
            } else {
                st.push(num);
                num = 0;
            }
        }
        return num;
    }
};