/**
 * Source: https://rb.gy/b26r4
 * Date: 2023/9/12
 * Skill:
 * Runtime: 25 ms, faster than 34.06% of C++ online submissions
 * Memory Usage: 23.19 MB, less than 25.81% of C++ online submissions
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
    TreeNode* root;
    unordered_map<int, TreeNode*> num2node;
    int sz = 0;
public:
    CBTInserter(TreeNode *node) {
        this->root = node;
        deque<TreeNode *> q;
        q.push_back(node);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop_front();
            sz++;
            num2node[sz] = cur;
            if (cur->left)
                q.push_back(cur->left);
            if (cur->right)
                q.push_back(cur->right);
        }
    }

    int insert(int val) {
        sz++;
        num2node[sz] = new TreeNode(val);
        if (sz % 2)
            num2node[sz / 2]->right = num2node[sz];
        else
            num2node[sz / 2]->left = num2node[sz];
        return num2node[sz / 2]->val;
    }

    TreeNode* get_root() {
        return root;
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