/**
 * Source: https://rb.gy/rs868
 * Date: 2023/8/31
 * Skill:
 * Runtime: 4 ms, faster than 62.90% of C++ online submissions
 * Memory Usage: 12.35 MB, less than 84.79% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef pair<int, int> pairs;

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        map<int, vector<vector<int>>> nodes;
        stack<tuple<TreeNode *, int, int>> mystack;
        TreeNode* cur_node = root;
        int cur_depth = -1;
        int left_most = 0, pos = 1, right_most = 0;
        while (cur_node) {
            pos--;
            cur_depth++;
            tuple<TreeNode *, int, int> mytuple (cur_node, pos, cur_depth);
            mystack.push(mytuple);
            left_most = min(left_most, pos);
            cur_node = cur_node->left;
        }
        while (!mystack.empty()) {
            tuple<TreeNode *, int, int> cur_pos = mystack.top();
            mystack.pop();
            if (nodes.find(get<1>(cur_pos)) == nodes.end()) {
                vector<vector<int>>v;
                nodes[get<1>(cur_pos)] = v;
            }
            vector<int> vv{get<2>(cur_pos), get<0>(cur_pos)->val};
            nodes[get<1>(cur_pos)].push_back(vv);
            left_most = min(left_most, get<1>(cur_pos));
            right_most = max(right_most, get<1>(cur_pos));
            if (get<0>(cur_pos)->right != nullptr) {
                TreeNode* node = get<0>(cur_pos)->right;
                pos = get<1>(cur_pos) + 1;
                int depth = get<2>(cur_pos) + 1;
                while (node != nullptr) {
                    tuple<TreeNode *, int, int> mytuple (node, pos, depth);
                    mystack.push(mytuple);
                    node = node->left;
                    pos--;
                    depth++;
                }
            }
        }
        for (int i = left_most; i <= right_most; i++) {
            sort(nodes[i].begin(), nodes[i].end(), [](vector<int> &a, vector<int> &b) {
                if (a[0] == b[0])
                    return a[1] < b[1];
                else
                    return a[0] < b[0];
            });
            vector<int> vec;
            for (auto j: nodes[i])
                vec.push_back(j[1]);
            res.push_back(vec);
        }
        return res;
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

}