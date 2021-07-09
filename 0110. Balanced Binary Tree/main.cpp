// Source: https://leetcode.com/problems/balanced-binary-tree/
// Date: 2021/7/9

#include<iostream>
#include<vector>
#include<cstdlib>
#include<unordered_map>    //note
using namespace std;

// Ref: https://shengyu7697.github.io/std-unordered_map/
// 對於需要高效率查詢的情況可以使用 unordered_map 容器,
// 而如果對記憶體消耗比較敏感或者資料存放要求排序的話則可以用 map 容器

// Definition for a binary tree node.
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
    unordered_map<TreeNode*, int>height;
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        if(isBalanced(root->left)) {
            if(isBalanced(root->right)) {
                if(abs(getHeight(root->left)-getHeight(root->right))<=1)
                    return true;
            }
        }
        return false;
    }
    int getHeight(TreeNode* root) {
        if(!root)
            return 0;
        if(!height.count(root))
            height[root] = 1+max(getHeight(root->left),getHeight(root->right));
        return height[root];
    }
};

/*使用std::ios::sync_with_stdio(false)和std::cin.tie(nullptr)
之后要避免和scanf和printf混用以避免出现问题。*/

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
