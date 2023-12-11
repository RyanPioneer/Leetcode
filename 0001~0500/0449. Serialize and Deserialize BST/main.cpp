/**
 * Source: jpeg.ly/0i9Nk
 * Date: 2023/12/9
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 97.73% of C++ online submissions
 * Memory Usage: 25.12 MB, less than 95.15% of C++ online submissions
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
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;
const int MX = 16;
ll mod = 1337;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (!root) return res;
        helper(root, res);
        res.pop_back();
        return res;
    }
    void helper(TreeNode* root, string &res) {
        res += to_string(root->val);
        if (root->left) {
            res.push_back('L');
            helper(root->left, res);
        }
        if (root->right) {
            res.push_back('R');
            helper(root->right, res);
        }
        res.push_back('B');
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        int idx = 0, len = data.length();
        while (idx < len && data[idx] != 'L' && data[idx] != 'R' && data[idx] != 'B') idx++;
        TreeNode* root = new TreeNode(stoi(data.substr(0, idx)));
        stack<TreeNode*> st;
        for (int i = idx; i < data.length(); i++) {
            if (data[i] == 'L' || data[i] == 'R') {
                bool left = data[i] == 'L';
                int start = ++i;
                while (i + 1 < len && data[i + 1] != 'L' && data[i + 1] != 'R' && data[i + 1] != 'B') i++;
                st.push(root);
                root = new TreeNode(stoi(data.substr(start, i - start + 1)));
                if (left) st.top()->left = root;
                else st.top()->right = root;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return root;
    }
};