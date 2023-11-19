/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/19
 * Skill:
 * Runtime: 448 ms, faster than 35.29% of C++ online submissions
 * Memory Usage: 202.50 MB, less than 5.88% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>


using namespace std;

const int MX = 5 * 1e4 + 1;

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
    void update_max(SegmentTreeNode * node, int pos, int num) {
        if (node == nullptr || pos < node->begin || pos > node->end)
            return;
        if (node->begin == node->end) {
            node->val = max(num, node->val);
            return;
        }
        if (pos <= node->mid) {
            if (node->left == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->begin, node->mid, 0) ;
                node->left = n;
            }
            update_max(node->left, pos, num);
            node->val = max(node->val, node->left->val);
        } else {
            if (node->right == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->mid + 1, node->end, 0) ;
                node->right = n;
            }
            update_max(node->right, pos, num);
            node->val = max(node->val, node->right->val);
        }
    }

    int query_min_index(SegmentTreeNode * node, int l, int r, int num) {
        if (node == nullptr || node->begin > r || node->end < l || node->val <= num)
            return -1;
        if (node->begin == node->end)
            return node->begin;
        if (node->left != nullptr && node->left->val > num && node->mid >= l) {
            int pos = query_min_index(node->left, l, r, num);
            if (pos != -1) return pos;
        }
        return query_min_index(node->right, l, r, num);
    }
};


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        SegmentTree *tree = new SegmentTree();
        for (int i = 0; i < n; i++) {
            tree->update_max(tree->root, i, heights[i]);
        }
        vector<int> res;
        for (auto &q: queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            if (left == right || heights[left] < heights[right]) {
                res.push_back(right);
                continue;
            }
            int ans = tree->query_min_index(tree->root, right + 1, n - 1, heights[left]);
            res.push_back(ans);
        }
        return res;
    }
};