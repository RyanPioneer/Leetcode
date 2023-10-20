/**
 * Source: tinyurl.com/yrb7fda8
 * Date: 2023/10/20
 * Skill:
 * Runtime: 110 ms, faster than 85.06% of C++ online submissions
 * Memory Usage: 30.29 MB, less than 63.31% of C++ online submissions
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


class Solution {
public:
    string robotWithString(string s) {
        int sz = s.length();
        char smallest_after[sz];
        char smallest = 'z' + 1;
        for (int i = sz - 1; i >= 0; i--) {
            smallest = min(smallest, s[i]);
            smallest_after[i] = smallest;
        }
        stack<char> st;
        string res;
        for (int i = 0; i < sz; i++) {
            while (!st.empty() && st.top() <= smallest_after[i]) {
                res.push_back(st.top());
                st.pop();
            }
            if (smallest_after[i] == s[i])
                res.push_back(s[i]);
            else
                st.push(s[i]);
        }
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}