/**
 * Source: https://rb.gy/300v5
 * Date: 2023/8/31
 * Skill:
 * Runtime: 44 ms, faster than 6.74% of C++ online submissions
 * Memory Usage: 213.59 MB, less than 5.56% of C++ online submissions
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
#include <set>
#include <string>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        return helper(expression, 0, expression.size() - 1);
    }
    bool helper(string expression, int start, int end) {
        if (start == end) return expression[start] == 't';
        vector<bool> operands;
        for (int i = start + 2; i <= end; i++) {
            if (expression[i] == '!' || expression[i] == '&' || expression[i] == '|') {
                int level = 1, j = i + 2;
                for (; j <= end; j++) {
                    if (expression[j] == '(') level++;
                    if (expression[j] == ')') level--;
                    if (level == 0) break;
                }
                operands.push_back(helper(expression, i, j));
                i = j;
            } else if (expression[i] == 't') {
                operands.push_back(true);
            } else if (expression[i] == 'f') {
                operands.push_back(false);
            }
        }
        return eval(expression[start], operands);
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