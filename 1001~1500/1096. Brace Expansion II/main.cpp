/**
 * Source: is.gd/9jOKTp
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 52.63% of C++ online submissions
 * Memory Usage: 19.82 MB, less than 29.82% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        string tmp;
        for (auto &c: expression) {
            if (isalpha(c)) {
                tmp.push_back('{');
                tmp.push_back(c);
                tmp.push_back('}');
            } else {
                tmp.push_back(c);
            }
        }
        expression = tmp;
        int len = SZ(tmp);
        stack<unordered_set<string>> strs;
        stack<int> op;  // 0: add 1: product
        unordered_set<string> cur;
        for (int i = 0; i < len; i++) {
            if (expression[i] == '{') {
                strs.push(cur);
                op.push(1);
                cur = {};
            } else if (expression[i] == ',') {
                strs.push(cur);
                op.push(0);
                cur = {};
            } else if (isalpha(expression[i])) {
                tmp.clear();
                tmp.push_back(expression[i]);
                while (i + 1 < len && isalpha(expression[i + 1])) {
                    tmp.push_back(expression[++i]);
                }
                cur.insert(tmp);
            } else {
                bool cont = true;
                while (!strs.empty() && cont) {
                    unordered_set<string> prev = strs.top();
                    strs.pop();
                    int prev_op = op.top();
                    op.pop();
                    if (prev_op == 1) {
                        cur = make_product(prev, cur);
                        cont = false;
                    } else {
                        cur.insert(begin(prev), end(prev));
                    }
                }
            }
        }
        while (!strs.empty()) {
            unordered_set<string> prev = strs.top();
            strs.pop();
            int prev_op = op.top();
            op.pop();
            if (prev_op == 1) {
                cur = make_product(prev, cur);
            } else {
                cur.insert(begin(prev), end(prev));
            }
        }
        vector<string> res;
        for (auto &s: cur) res.push_back(s);
        sort(begin(res), end(res));
        return res;
    }
    unordered_set<string> make_product(unordered_set<string> first, unordered_set<string> second) {
        if (SZ(first) == 0) first.insert("");
        if (SZ(second) == 0) second.insert("");
        unordered_set<string> tmp;
        for (auto &s1: first) {
            for (auto &s2: second) {
                tmp.insert(s1 + s2);
            }
        }
        return tmp;
    }
};