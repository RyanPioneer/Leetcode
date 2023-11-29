/**
 * Source: is.gd/UDB2F6
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 32.92% of C++ online submissions
 * Memory Usage: 25.87 MB, less than 61.67% of C++ online submissions
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
    int pre_index = 0, post_index = 0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[pre_index++]);
        if (root->val != postorder[post_index]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if (root->val != postorder[post_index]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        post_index++;
        return root;
    }
};