/**
 * Source: t.ly/UfhCf
 * Date: 2024/5/22
 * Skill:
 * Ref:
 * Runtime: 18 ms, faster than 88.83% of C++ online submissions
 * Memory Usage: 22.47 MB, less than 7.48% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define MK make_pair
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;
typedef pair<int, string> pis;
const int MX = 1e5+7;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> v;

        function<void(TreeNode*)>inorder = [&](TreeNode* node) {
            if (!node) return;
            inorder(node->left);
            v.push_back(node);
            inorder(node->right);
        };

        inorder(root);
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == p) {
                return i == v.size()-1 ? nullptr : v[i+1];
            }
        }
        return nullptr;
    }
};