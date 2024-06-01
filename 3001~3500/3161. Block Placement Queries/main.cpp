/**
 * Source: t.ly/sV82l
 * Date: 2024/5/26
 * Skill:
 * Ref:
 * Runtime: 953 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 300.97 MB, less than 100.00% of C++ online submissions
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
ll mod = 1e9+7;
const int MX = 1e5+1;


class SegmentTreeNode {
public:
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    int begin;
    int end;
    int mid;
    int val;

    SegmentTreeNode(int b, int e, int v) {
        begin = b;
        end = e;
        mid = (b + e) / 2;
        val = v;
        left = nullptr;
        right = nullptr;
    }

    SegmentTreeNode(int b, int e, int v, SegmentTreeNode *l, SegmentTreeNode *r) {
        begin = b;
        end = e;
        mid = (b + e) / 2;
        val = v;
        left = l;
        right = r;
    }
};


class SegmentTree {
public:
    SegmentTreeNode *root;
    SegmentTree() {
        root = new SegmentTreeNode(0, MX, 0);
    }
    void update_delta(SegmentTreeNode * node, int pos, int delta) {
        if (node == nullptr)
            return;
        if (pos < node->begin || pos > node->end)
            return;
        if (pos == node->begin && pos == node->end) {
            node->val = delta;
            return;
        }
        if (pos <= node->mid) {
            if (node->left == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->begin, node->mid, 0) ;
                node->left = n;
            }
            update_delta(node->left, pos, delta);
        } else {
            if (node->right == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->mid + 1, node->end, 0) ;
                node->right = n;
            }
            update_delta(node->right, pos, delta);
        }
        node->val = 0;
        if (node->left != nullptr)
            node->val = max(node->val, node->left->val);
        if (node->right != nullptr)
            node->val = max(node->val, node->right->val);
    }

    int query_range_max(SegmentTreeNode * node, int l, int r) {
        if (node->begin > r || node->end < l)
            return 0;
        if (node->begin >= l && node->end <= r)
            return node->val;
        int num1 = INT32_MIN, num2 = INT32_MIN;
        if (node->left != nullptr) {
            num1 = query_range_max(node->left, l, r);
        }
        if (node->right != nullptr) {
            num2 = query_range_max(node->right, l, r);
        }
        return max(num1, num2);
    }
};


class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        SegmentTree *tree = new SegmentTree();
        tree->update_delta(tree->root, MX-1, MX-1);
        set<int> nums;
        nums.insert(MX-1);
        vector<bool> res;
        for (auto &q: queries) {
            if (q[0] == 1) {
                nums.insert(q[1]);
                auto it = nums.lower_bound(q[1]);
                int nx = *next(it);
                tree->update_delta(tree->root, nx, nx - q[1]);
                if (it == begin(nums)) {
                    tree->update_delta(tree->root, q[1], q[1]);
                } else {
                    int pv = *prev(it);
                    tree->update_delta(tree->root, q[1], q[1]-pv);
                }
            } else {
                if (nums.empty() || *begin(nums) > q[1]) {
                    res.push_back(q[2] <= q[1]);
                    continue;
                }
                auto it = nums.lower_bound(q[1]);
                if (min(*it, q[1]) - *prev(it) >= q[2]) {
                    res.push_back(true);
                    continue;
                }
                int i = tree->query_range_max(tree->root, 0, q[1]);
                res.push_back(i >= q[2]);
            }
        }
        return res;
    }
};