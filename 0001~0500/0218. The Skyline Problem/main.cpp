/**
 * Source: https://rb.gy/7cpqr
 * Date: 2023/9/13
 * Skill:
 * Runtime: 42 ms, faster than 23.24% of C++ online submissions
 * Memory Usage: 19.30 MB, less than 9.73% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    class SegmentTreeNode {
    public:
        int val, start, end, mid;
        SegmentTreeNode *left, *right;
        SegmentTreeNode(int n, int s, int e) {
            val = n, start = s, end = e, mid = s + (e - s) / 2;
            left = right = NULL;
        }
    };
    class SegmentTree {
    public:
        SegmentTreeNode *root;
        SegmentTree() {
            root = new SegmentTreeNode(0, 0, INT_MAX);
        }
        void update_range(SegmentTreeNode *node, int s, int e, int num) {
            if (node->start > e || node->end < s)
                return;
            if (node->start == node->end) {
                node->val = max(node->val, num);
                return;
            }
            if (node->start >= s && node->end <= e) {
                node->val = max(node->val, num);
                if (node->left)
                    update_range(node->left, s, e, num);
                if (node->right)
                    update_range(node->right, s, e, num);
                return;
            }
            if (!node->left)
                node->left = new SegmentTreeNode(node->val, node->start, node->mid);
            if (!node->right)
                node->right = new SegmentTreeNode(node->val, node->mid + 1, node->end);
            update_range(node->left, s, e, num);
            update_range(node->right, s, e, num);
        }
        int query_num(SegmentTreeNode *node, int index) {
            if (node->start > index || node->end < index)
                return 0;
            if (index <= node->mid) {
                if (node->left)
                    return query_num(node->left, index);
                else
                    return node->val;
            } else {
                if (node->right)
                    return query_num(node->right, index);
                else
                    return node->val;
            }
        }
    };
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        SegmentTree *tree = new SegmentTree();
        set<int> points;
        for (auto i: buildings) {
            points.insert(i[0]);
            points.insert(i[1]);
            tree->update_range(tree->root, i[0], i[1] - 1, i[2]);
        }
        int cur_height = 0;
        for (auto i: points) {
            int height = tree->query_num(tree->root, i);
            if (cur_height != height) {
                cur_height = height;
                res.push_back({i, cur_height});
            }
        }
        return res;
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
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<vector<int>> res = s.getSkyline(arr);
    for (auto i: res)
        cout << i[0] << " " << i[1] << " " << endl;
}