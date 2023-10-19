/**
 * Source: tinyurl.com/yrqmcugm
 * Date: 2023/10/19
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class TextEditor {
    int idx = 0;
    string s = "";
public:
    TextEditor() {
    }

    void addText(string text) {
        int sz = text.length();
        s.insert(idx, text);
        idx += sz;
    }

    int deleteText(int k) {
        int sz = min(idx, k);
        idx -= sz;
        s.erase(idx, sz);
        return sz;
    }

    string cursorLeft(int k) {
        idx = max(0, idx - k);
        int sz = min(idx, 10);
        return s.substr(idx - sz, sz);
    }

    string cursorRight(int k) {
        idx = min((int)s.length(), idx + k);
        int sz = min(idx, 10);
        return s.substr(idx - sz, sz);
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