/**
 * Source: t.ly/AW6EQ
 * Date: 2023/11/2
 * Skill:
 * Runtime: 3 ms, faster than 92.80% of C++ online submissions
 * Memory Usage: 12.49 MB, less than 21.30% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


typedef pair<int, int> pairs;

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
    int averageOfSubtree(TreeNode* root) {
        int res = 0;
        function<pairs(TreeNode *)> dfs;
        dfs = [&](TreeNode *node) {
            if (node == nullptr) return make_pair(0, 0);
            int sum = node->val, num = 1;
            auto[s1, n1] = dfs(node->left);
            auto[s2, n2] = dfs(node->right);
            sum += s1 + s2;
            num += n1 + n2;
            if (node->val  == sum / num) res++;
            return make_pair(sum, num);
        };
        dfs(root);
        return res;
    }
};


int main() {
    Solution s;
}