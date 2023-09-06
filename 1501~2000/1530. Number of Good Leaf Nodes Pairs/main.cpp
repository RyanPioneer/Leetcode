/**
 * Source: https://rb.gy/mq96b
 * Date: 2023/9/6
 * Skill:
 * Runtime: 47 ms, faster than 92.32% of C++ online submissions
 * Memory Usage: 32.6 MB, less than 96.80% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= distance <= 10
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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<int> dis;
    int res = 0, distance;
public:
    int countPairs(TreeNode* root, int distance) {
        this->distance = distance;
        dis.resize(distance);
        post_order_traversal(root);
        return res;
    }
    void post_order_traversal(TreeNode* cur) {
        if (cur->left == nullptr && cur->right == nullptr) {
            std::fill(dis.begin(), dis.end(), 0);
            dis[0] = 1;
            return;
        }
        vector<int> left, right;
        if (cur->left) {
            post_order_traversal(cur->left);
            left = dis;
        }
        if (cur->right) {
            post_order_traversal(cur->right);
            right = dis;
        }
        if (!cur->left || !cur->right) {
            for (int i = dis.size() - 1; i > 0; i--)
                dis[i] = dis[i - 1];
            dis[0] = 0;
        } else {
            for (int i = 0; i <= distance - 1; i++) {
                if (left[i] != 0) {
                    for (int j = 0; i + j <= distance - 2; j++)
                        res += left[i] * right[j];
                }
            }
            for (int i = dis.size() - 1; i > 0; i--)
                dis[i] = left[i - 1] + right[i - 1];
            dis[0] = 0;
        }
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
//    Solution s;
    vector<int> left;
    cout << left.size() << endl;
}