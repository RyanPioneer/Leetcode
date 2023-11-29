/**
 * Source: is.gd/UDB2F6
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 56.88% of C++ online submissions
 * Memory Usage: 24.67 MB, less than 99.38% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        vector<TreeNode *> st;
        st.push_back(new TreeNode(preorder[0]));
        for (int pre_index = 1, post_index = 0; pre_index < SZ(preorder); pre_index++) {
            while (st.back()->val == postorder[post_index]) {
                st.pop_back();
                post_index++;
            }
            TreeNode *cur = new TreeNode(preorder[pre_index]);
            if (st.back()->left == nullptr) {
                st.back()->left = cur;
            } else {
                st.back()->right = cur;
            }
            st.push_back(cur);
        }
        return st[0];
    }
};