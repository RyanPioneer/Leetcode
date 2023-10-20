/**
 * Source: tinyurl.com/yrb7fda8
 * Date: 2023/10/20
 * Skill:
 * Runtime: 526 ms, faster than 11.36% of C++ online submissions
 * Memory Usage: 84.08 MB, less than 8.44% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= s.length <= 10 ** 5
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
        int smaller_after[sz];
        vector<pair<char, int>> arr;
        for (int i = 0; i < sz; i++) {
            arr.push_back({s[i], i});
            smaller_after[i] = -1;
        }
        sort(arr.rbegin(), arr.rend());
        int idx = 0;
        for (int i = sz - 1; i >= 0; i--) {
            while (idx < sz && s[i] < arr[idx].first)
                smaller_after[arr[idx++].second] = i;
        }
        stack<int> st;
        string res;
        for (int i = 0; i < sz; i++) {
            if (smaller_after[i] > i)
                st.push(i);
            else {
                res.push_back(s[i]);
                while (!st.empty() && smaller_after[st.top()] <= i) {
                    res.push_back(s[st.top()]);
                    st.pop();
                }
            }
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