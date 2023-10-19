/**
 * Source: tinyurl.com/yrqmcugm
 * Date: 2023/10/19
 * Skill:
 * Runtime: 790 ms, faster than 21.00% of C++ online submissions
 * Memory Usage: 304.36 MB, less than 10.33% of C++ online submissions
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
    list<char> s;
    list<char>::iterator iter;
public:
    TextEditor() {
        iter = s.begin();
    }

    void addText(string text) {
        for (auto c: text)
            s.insert(iter, c);
    }

    int deleteText(int k) {
        int num = 0;
        for (int i = 0; i < k; i++) {
            if (iter == begin(s))
                break;
            num++;
            s.erase(prev(iter));
        }
        return num;
    }

    string cursorLeft(int k) {
        for (int i = 0; i < k; i++) {
            if (iter == begin(s))
                break;
            iter = prev(iter);
        }
        string res;
        list<char>::iterator tmp = iter;
        for (int i = 0; i < 10; i++) {
            if (tmp == begin(s))
                break;
            res.push_back(*prev(tmp));
            tmp = prev(tmp);
        }
        reverse(begin(res), end(res));
        return res;
    }

    string cursorRight(int k) {
        for (int i = 0; i < k; i++) {
            if (iter == end(s))
                break;
            iter = next(iter);
        }
        string res;
        list<char>::iterator tmp = iter;
        for (int i = 0; i < 10; i++) {
            if (tmp == begin(s))
                break;
            res.push_back(*prev(tmp));
            tmp = prev(tmp);
        }
        reverse(begin(res), end(res));
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