/**
 * Source: is.gd/Sx9Lro
 * Date: 2023/12/7
 * Skill:
 * Ref:
 * Runtime: 42 ms, faster than 73.03% of C++ online submissions
 * Memory Usage: 12.02 MB, less than 68.28% of C++ online submissions
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
    unordered_set<string> res;
    int len, mx_len = 0;
public:
    vector<string> removeInvalidParentheses(string s) {
        len = s.length();
        vector<int> par(len, 1);
        helper(s, par, 0, 0);
        vector<string> ans;
        for (auto &i: res) ans.push_back(i);
        return ans;
    }
    void helper(string &s, vector<int>& par, int left, int idx) {
        if (left < 0) return;
        if (left > len - idx) return;
        if (idx == len) {
            if (left == 0) {
                string ss;
                for (int i = 0; i < len; i++) {
                    if (par[i]) ss.push_back(s[i]);
                }
                if (ss.length() >= mx_len) {
                    if (ss.length() > mx_len) {
                        res.clear();
                        mx_len = ss.length();
                    }
                    res.insert(ss);
                }
            }
            return;
        }
        if (s[idx] == '(') {
            helper(s, par, left + 1, idx + 1);
            par[idx] = 0;
            helper(s, par, left, idx + 1);
            par[idx] = 1;
        } else if (s[idx] == ')') {
            helper(s, par, left - 1, idx + 1);
            par[idx] = 0;
            helper(s, par, left, idx + 1);
            par[idx] = 1;
        } else {
            helper(s, par, left, idx + 1);
        }
    }
};