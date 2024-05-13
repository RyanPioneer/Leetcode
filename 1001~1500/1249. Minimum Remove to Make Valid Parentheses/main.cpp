/**
 * Source: ibit.ly/Dt-Bs
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 18 ms, faster than 74.71% of C++ online submissions
 * Memory Usage: 13.58 MB, less than 20.61% of C++ online submissions
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
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> Set;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    Set.insert(i);
                }
            }
        }
        while (!st.empty()) {
            Set.insert(st.top());
            st.pop();
        }
        string res;
        for (int i = 0; i < s.length(); i++) {
            if (Set.find(i) == end(Set)) {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};