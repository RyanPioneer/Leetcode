/**
 * Source: ibit.ly/gKGuk
 * Date: 2024/6/26
 * Skill:
 * Ref:
 * Runtime: 23 ms, faster than 80.54% of C++ online submissions
 * Memory Usage: 23.97 MB, less than 97.30% of C++ online submissions
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
#define ll long long


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    TreeNode* str2tree(string s) {
        stack<TreeNode *> st;
        TreeNode *cur;
        for (int i = 0; i < s.length(); i++) {
            if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-') {
                int val = 0, neg = s[i] == '-' ? -1 : 1;
                if (s[i] == '-') i++;
                while (s[i] >= '0' && s[i] <= '9') {
                    val = val * 10 + s[i] - '0';
                    i++;
                }
                i--;
                cur = new TreeNode(val * neg);
                if (!st.empty()) {
                    if (!st.top()->left) {
                        st.top()->left = cur;
                    } else {
                        st.top()->right = cur;
                    }
                }
            } else if (s[i] == '(') {
                st.push(cur);
            } else {
                cur = st.top();
                st.pop();
            }
        }
        return cur;
    }
};