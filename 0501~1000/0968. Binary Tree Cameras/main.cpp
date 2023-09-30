/**
 * Source: ibit.ly/CBxSQ
 * Date: 2023/9/30
 * Skill:
 * Runtime: 7 ms, faster than 72.07% of C++ online submissions
 * Memory Usage: 24.03 MB, less than 18.37% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      The number of nodes in the tree is in the range [1, 1000].
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;



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
    unordered_set<TreeNode*> covered;
    int res = 0;
public:
    int minCameraCover(TreeNode* root) {
        covered.insert(nullptr);
        dfs(root, nullptr);
        return res;
    }
    void dfs(TreeNode* node, TreeNode* par) {
        if (node == nullptr)
            return;
        dfs(node->left, node);
        dfs(node->right, node);
        if (covered.find(node->left) == covered.end() || covered.find(node->right) == covered.end()
            || (par == nullptr && covered.find(node) == covered.end())) {
            covered.insert(node->left);
            covered.insert(node->right);
            covered.insert(node);
            covered.insert(par);
            res++;
        }
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}