/**
 * Source: is.gd/NkK7EG
 * Date: 2023/12/7
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 36.76% of C++ online submissions
 * Memory Usage: 12.04 MB, less than 87.57% of C++ online submissions
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


class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();
    // Constructor initializes a single integer.
    NestedInteger(int value);
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);
    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class Solution {
public:
    NestedInteger deserialize(string s) {
        if (s[0] != '[') {
            return NestedInteger(stoi(s.substr(0)));
        }
        stack<NestedInteger> st;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '[') {
                st.push(NestedInteger());
            } else if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
                int start = i;
                while (i + 1 < len && s[i + 1] != ',' && s[i + 1] != ']') i++;
                int num = stoi(s.substr(start, i - start + 1));
                st.top().add(NestedInteger(num));
            } else if (s[i] == ']') {
                if (st.size() > 1) {
                    NestedInteger prev = st.top();
                    st.pop();
                    st.top().add(prev);
                }
            }
        }
        return st.top();
    }
};