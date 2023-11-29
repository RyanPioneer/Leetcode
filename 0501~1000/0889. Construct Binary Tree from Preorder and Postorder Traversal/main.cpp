/**
 * Source: is.gd/UDB2F6
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 86.71% of C++ online submissions
 * Memory Usage: 27.10 MB, less than 10.82% of C++ online submissions
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
        return helper(preorder, postorder, 0, SZ(preorder) - 1, 0, SZ(postorder) - 1);
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& postorder, int a, int b, int c, int d) {
        TreeNode* root = new TreeNode(preorder[a]);
        if (a == b) return root;
        if (preorder[a + 1] == postorder[d - 1]) {
            root->left = helper(preorder, postorder, a + 1, b, c, d - 1);
        } else {
            int left = d, right = a;
            while (postorder[left] != preorder[a + 1]) left--;
            while (preorder[right] != postorder[d - 1]) right++;
            root->left = helper(preorder, postorder, a + 1, right - 1, c, left);
            root->right = helper(preorder, postorder, right, b, left + 1, d - 1);
        }
        return root;
    }
};