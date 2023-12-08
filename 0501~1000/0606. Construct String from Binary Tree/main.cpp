/**
 * Source: jpeg.ly/Ex3EC
 * Date: 2023/12/8
 * Skill:
 * Ref:
 * Runtime: 16 ms, faster than 55.74% of C++ online submissions
 * Memory Usage: 143.61 MB, less than 8.71% of C++ online submissions
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


class Solution {
    string res;
public:
    string tree2str(TreeNode* root) {
        helper(root);
        return res;
    }
    void helper(TreeNode* root) {
        res += to_string(root->val);
        if (root->left) {
            res.push_back('(');
            tree2str(root->left);
            res.push_back(')');
        }
        if (root->right) {
            if (!root->left) {
                res += "()";
            }
            res.push_back('(');
            tree2str(root->right);
            res.push_back(')');
        }
    }
};