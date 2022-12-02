/** 
 * Source: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Date: 2022/7/14
 * Skill: Recursive
 * Runtime: 39 ms
 * Memory Usage: 74 MB
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *     
 */

#include <iostream>
#include <vector>

using namespace std;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int index = 0;
        while (inorder[index] != preorder[0])
            index++;
        if (index != 0) {
            vector<int> left_pre = {preorder.begin()+1, preorder.begin()+index+1};
            vector<int> left_in = {inorder.begin(), inorder.begin()+index};
            root->left = buildTree(left_pre,left_in);
        }
        if (index != inorder.size()-1) {
            vector<int> right_pre = {preorder.begin()+index+1, preorder.end()};
            vector<int> right_in = {inorder.begin()+index+1, inorder.end()};
            root->right = buildTree(right_pre,right_in);
        }
        return root;
    }
};
static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
