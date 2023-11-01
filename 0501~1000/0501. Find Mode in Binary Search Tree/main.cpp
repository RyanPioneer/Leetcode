/**
 * Source: t.ly/bf42x
 * Date: 2023/11/1
 * Skill:
 * Runtime: 10 ms, faster than 93.21% of C++ online submissions
 * Memory Usage: 24.28 MB, less than 91.46% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


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
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int num = INT32_MIN, cnt = 0, max_freq = 1;
        function<void(TreeNode*, bool)> inorder;
        inorder = [&](TreeNode* node, bool find_res) {
            if (node == nullptr) return;
            inorder(node->left, find_res);
            if (node->val == num) {
                cnt++;
                if (max_freq < cnt && !find_res) max_freq = cnt;
            } else {
                num = node->val;
                cnt = 1;
            }
            if (max_freq == cnt && find_res) res.push_back(num);
            inorder(node->right, find_res);
        };
        inorder(root, false);
        num = INT32_MIN, cnt = 0;
        inorder(root, true);
        return res;
    }
};



int main() {
    Solution s;
}