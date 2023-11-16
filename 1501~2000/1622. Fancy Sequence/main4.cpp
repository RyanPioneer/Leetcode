/**
 * Source: ibit.ly/PH-4e
 * Date: 2023/11/16
 * Skill:
 * Runtime: 596 ms, faster than 19.73% of C++ online submissions
 * Memory Usage: 227.52 MB, less than 14.29% of C++ online submissions
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


#define ll long long
ll mod = 1e9+7;

const int MX = 1e5+1;


class SegmentTreeNode {
public:
    SegmentTreeNode *left, *right;
    int begin, end, mid;
    ll total, add, mul;
    SegmentTreeNode(int a, int b) : left(nullptr), right(nullptr), total(0), add(0), mul(1) {
        begin = a;
        end = b;
        mid = (a + b) / 2;
    }
};

class SegmentTree {
public:
    SegmentTreeNode * root;
    SegmentTree() {
        root = new SegmentTreeNode(0, MX - 1);
    }

    void update_add(SegmentTreeNode * node, int l, int r, int num) {
        if (l > node->end || r < node->begin) return;
        if (l <= node->begin && r >= node->end) {
            node->total = (node->total + (node->end - node->begin + 1) * num) % mod;
            node->add = (node->add + num) % mod;
            return;
        }
        push_down(node);
        update_add(node->left, l, r, num);
        update_add(node->right, l, r, num);
        push_up(node);
    }

    void update_mul(SegmentTreeNode * node, int l, int r, int num) {
        if (l > node->end || r < node->begin) return;
        if (l <= node->begin && r >= node->end) {
            node->total = node->total * num % mod;
            node->add = node->add * num % mod;
            node->mul = node->mul * num % mod;
            return;
        }
        push_down(node);
        update_mul(node->left, l, r, num);
        update_mul(node->right, l, r, num);
        push_up(node);
    }

    void push_down(SegmentTreeNode * node) {
        if (node->left == nullptr) {
            node->left = new SegmentTreeNode(node->begin, node->mid);
        }
        if (node->right == nullptr) {
            node->right = new SegmentTreeNode(node->mid + 1, node->end);
        }
        if (node->add || node->mul != 1) {
            ll add = node->add, mul = node->mul;
            node->left->total = (node->left->total * mul + (node->mid - node->begin + 1) * add) % mod;
            node->right->total = (node->right->total * mul + (node->end - node->mid) * add) % mod;
            node->left->add = (node->left->add * mul + add) % mod;
            node->right->add = (node->right->add * mul + add) % mod;
            node->left->mul = node->left->mul * mul % mod;
            node->right->mul = node->right->mul * mul % mod;
            node->add = 0;
            node->mul = 1;
        }
    }

    void push_up(SegmentTreeNode * node) {
        node->total = (node->left->total + node->right->total) % mod;
    }

    ll query_num(SegmentTreeNode * node, int l, int r) {
        if (l > node->end || r < node->begin) return 0;
        if (l <= node->begin && r >= node->end) return node->total;
        push_down(node);
        return (query_num(node->left, l, r) + query_num(node->right, l, r)) % mod;
    }
};


class Fancy {
    SegmentTree *tree = new SegmentTree();
    int idx = 0;
public:
    Fancy() {

    }

    void append(int val) {
        idx++;
        tree->update_add(tree->root, idx, idx, val);
    }

    void addAll(int inc) {
        tree->update_add(tree->root, 1, idx, inc);
    }

    void multAll(int m) {
        tree->update_mul(tree->root, 1, idx, m);
    }

    int getIndex(int idx) {
        return idx < this->idx ? tree->query_num(tree->root, idx + 1, idx + 1) : -1;
    }
};


int main() {
}