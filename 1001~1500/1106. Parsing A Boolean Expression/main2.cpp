/**
 * Source: https://rb.gy/300v5
 * Date: 2023/8/31
 * Skill:
 * Runtime: 19 ms, faster than 27.42% of C++ online submissions
 * Memory Usage: 10.8 MB, less than 12.29% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= expression.length <= 2 * 10 ** 4
 *      expression[i] is one following characters: '(', ')', '&', '|', '!', 't', 'f', and ','.
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <stack>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> ope;
        stack<vector<bool>> operands;
        vector<bool> vals;
        bool res;
        for (int i = 0; i < expression.length(); i++) {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|') {
                ope.push(expression[i]);
                operands.push(vals);
                vals.clear();
            }  else if (expression[i] == ')') {
                res = eval(ope.top(), vals);
                ope.pop();
                vals = operands.top();
                operands.pop();
                vals.push_back(res);
            } else if (expression[i] == 'f' || expression[i] == 't')
                vals.push_back(expression[i] == 't');
        }
        return res;
    }
    bool eval(char ope, vector<bool> operands) {
        bool res;
        if (ope == '!')
            return !operands[0];
        else if (ope == '&') {
            res = true;
            for (auto i: operands)
                res = res && i;
        } else if (ope == '|') {
            res = false;
            for (auto i: operands)
                res = res || i;
        }
        return res;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    string ss = "t";
    bool res = s.parseBoolExpr(ss);
    cout << res << endl;
}