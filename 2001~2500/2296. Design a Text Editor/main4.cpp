/**
 * Source: tinyurl.com/yrqmcugm
 * Date: 2023/10/19
 * Skill:
 * Runtime: 324 ms, faster than 48.33% of C++ online submissions
 * Memory Usage: 129.36 MB, less than 37.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class TextEditor {
    stack<char> left, right;
public:
    TextEditor() {
    }

    void addText(string text) {
        for (auto c: text)
            left.push(c);
    }

    int deleteText(int k) {
        int num = min(k, (int)left.size());
        for (int i = 0; i < num; i++)
            left.pop();
        return num;
    }

    string cursorLeft(int k) {
        k = min(k, (int)left.size());
        for (int i = 0; i < k; i++) {
            char c = left.top();
            left.pop();
            right.push(c);
        }
        string res;
        stack<char> tmp;
        for (int i = 0; i < 10; i++) {
            if (left.empty())
                break;
            char c = left.top();
            left.pop();
            res.push_back(c);
            tmp.push(c);
        }
        reverse(begin(res), end(res));
        while (!tmp.empty()) {
            char c = tmp.top();
            tmp.pop();
            left.push(c);
        }
        return res;
    }

    string cursorRight(int k) {
        k = min(k, (int)right.size());
        for (int i = 0; i < k; i++) {
            char c = right.top();
            right.pop();
            left.push(c);
        }
        string res;
        stack<char> tmp;
        for (int i = 0; i < 10; i++) {
            if (left.empty())
                break;
            char c = left.top();
            left.pop();
            res.push_back(c);
            tmp.push(c);
        }
        reverse(begin(res), end(res));
        while (!tmp.empty()) {
            char c = tmp.top();
            tmp.pop();
            left.push(c);
        }
        return res;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}