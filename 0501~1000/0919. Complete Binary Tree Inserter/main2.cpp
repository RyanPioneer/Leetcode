/**
 * Source: https://rb.gy/b26r4
 * Date: 2023/9/12
 * Skill:
 * Runtime: 16 ms, faster than 74.40% of C++ online submissions
 * Memory Usage: 22.3 MB, less than 92.62% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter {
    vector<TreeNode *>tree;
public:
    CBTInserter(TreeNode *node) {
        tree.push_back(node);
        for (int i = 0; i < tree.size(); i++) {
            if (tree[i]->left)
                tree.push_back(tree[i]->left);
            if (tree[i]->right)
                tree.push_back(tree[i]->right);
        }
    }

    int insert(int val) {
        tree.push_back(new TreeNode(val));
        int num = tree.size();
        if (num % 2)
            tree[num / 2 - 1]->right = tree[num - 1];
        else
            tree[num / 2 - 1]->left = tree[num - 1];
        return tree[num / 2 - 1]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
};



static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}