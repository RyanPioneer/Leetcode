/**
 * Source: t.ly/J-DFJ
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 132 ms, faster than 82.82% of C++ online submissions
 * Memory Usage: 22.86 MB, less than 87.67% of C++ online submissions
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
    string clearStars(string s) {
        int n = s.length();
        vector<int> st[26];
        for (int i = 0; i < s.length(); i++) {
            char &c = s[i];
            if (c != '*') {
                st[c - 'a'].push_back(i);
            } else {
                for (int j = 0; j < 26; j++) {
                    if (!st[j].empty()) {
                        st[j].pop_back();
                        break;
                    }
                }
            }
        }
        for (int j = 0; j < 26; j++) reverse(begin(st[j]), end(st[j]));
        string res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (!st[j].empty() && st[j].back() == i) {
                    res.push_back('a' + j);
                    st[j].pop_back();
                    break;
                }
            }
        }
        return res;
    }
};