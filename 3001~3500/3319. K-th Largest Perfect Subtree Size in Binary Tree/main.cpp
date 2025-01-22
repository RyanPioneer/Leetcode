/**
 * Source: is.gd/z7sWF9
 * Date: 2025/1/22
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 64.68 MB, less than 87.04% of C++ online submissions
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
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            int left = 0, right = 0;
            if (node->left) {
                left = dfs(node->left);
            }
            if (node->right) {
                right = dfs(node->right);
            }
            if (left == right) {
                if (minHeap.size() < k) {
                    minHeap.push(left * 2 + 1);
                } else if (minHeap.top() < left * 2 + 1) {
                    minHeap.pop();
                    minHeap.push(left * 2 + 1);
                }
                return left * 2 + 1;
            } else {
                return -1;
            }
        };

        dfs(root);
        return minHeap.size() == k ? minHeap.top() : -1;
    }
};
