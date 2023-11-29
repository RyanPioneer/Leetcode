/**
 * Source: is.gd/sODYmr
 * Date: 2023/11/29
 * Skill: Discretization, Sweep line, Segment Tree
 * Ref:
 * Runtime: 4 ms, faster than 94.59% of C++ online submissions
 * Memory Usage: 10.70 MB, less than 33.11% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef pair<int, int> PII;
ll mod = 1e9+7;
const int MX = 201, IN = 1, OUT = -1;


class SegmentTreeNode {
    friend class SegmentTree;
    SegmentTreeNode *left, *right;
    int begin, end, mid, cur_len, cover;
    SegmentTreeNode(int l, int r) : begin(l), end(r) {
        mid = (begin + end) / 2;
        cur_len = cover = 0;
        left = right = nullptr;
    }
};


class SegmentTree {
    SegmentTreeNode *root = new SegmentTreeNode(0, MX);
public:

    int query() {return root->cur_len;}

    void update(int l, int r, int num, unordered_map<int, int>& yidx2num) {
        update(root, l, r, num, yidx2num);
    }

    void update(SegmentTreeNode *node, int l, int r, int num, unordered_map<int, int>& yidx2num) {
        if (l > node->end || r < node->begin) return;
        if (l <= node->begin && node->end <= r) {
            node->cover += num;
            push_up(node, yidx2num);
            return;
        }
        make_children(node);
        update(node->left, l, r, num, yidx2num);
        update(node->right, l, r, num, yidx2num);
        push_up(node, yidx2num);
    }

    void push_up(SegmentTreeNode *node, unordered_map<int, int>& yidx2num) {
        if (node == nullptr) return;
        if (node->cover > 0) {
            node->cur_len = yidx2num[node->end + 1] - yidx2num[node->begin];
        } else if (node->begin < node->end) {
            push_up(node->left, yidx2num);
            push_up(node->right, yidx2num);
            node->cur_len = node->left == nullptr ? 0 : node->left->cur_len;
            node->cur_len += node->right == nullptr ? 0 : node->right->cur_len;
        } else {
            node->cur_len = 0;
        }
    }

    void make_children(SegmentTreeNode *node) {
        if (node->left == nullptr) {
            node->left = new SegmentTreeNode(node->begin, node->mid);
        }
        if (node->right == nullptr) {
            node->right = new SegmentTreeNode(node->mid + 1, node->end);
        }
    }
};


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> y_set;
        unordered_map<int, int> yidx2num, num2yidx;
        vector<array<int, 4>> pos;
        for (auto &r: rectangles) {
            y_set.insert(r[1]);
            y_set.insert(r[3]);
            pos.push_back({r[0], r[1], r[3], IN});
            pos.push_back({r[2], r[1], r[3], OUT});
        }
        int count = 0, len = SZ(pos);
        for (auto i: y_set) {
            yidx2num[count] = i;
            num2yidx[i] = count++;
        }
        sort(begin(pos), end(pos));

        SegmentTree *tree = new SegmentTree();
        ll res = 0;
        for (int i = 0; i < len - 1; i++) {
            int x = pos[i][0], down = num2yidx[pos[i][1]], up = num2yidx[pos[i][2]];
            tree->update(down, up - 1, pos[i][3], yidx2num);
            ll cur_len = tree->query();
            res += cur_len * (pos[i + 1][0] - x);
        }
        return res % mod;
    }
};