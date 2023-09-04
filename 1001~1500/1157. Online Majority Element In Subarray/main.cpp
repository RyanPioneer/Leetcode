/**
 * Source: https://rb.gy/d7i01
 * Date: 2023/9/2
 * Skill: Segment tree, Boyer–Moore majority vote algorithm
 * Runtime: 351 ms, faster than 52.14% of C++ online submissions
 * Memory Usage: 159.7 MB, less than 8.55% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 * threshold > right - left + 1
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class MajorityChecker {
    class SegmentTreeNode {
    public:
        int most_val;
        int freq_diff;
        SegmentTreeNode *left;
        SegmentTreeNode *right;
        int start;
        int mid;
        int end;
        SegmentTreeNode(int s, int e) {
            start = s;
            mid = (s + e) / 2;
            end = e;
            left = nullptr;
            right = nullptr;
            most_val = 0;
            freq_diff = 0;
        }
    };
    class SegmentTree {
    public:
        SegmentTreeNode *root;
        vector<int> arr;
        SegmentTree(vector<int> v) {
            arr = v;
            root = build_tree(0, arr.size() - 1);
        }
        SegmentTreeNode *build_tree(int s, int e) {
            if (s == e) {
                SegmentTreeNode *node = new SegmentTreeNode(s, e);
                node->most_val = arr[s];
                node->freq_diff = 1;
                return node;
            }
            SegmentTreeNode *node = new SegmentTreeNode(s, e);
            node->left = build_tree(s, node->mid);
            node->right = build_tree(node->mid + 1, e);
            if (node->left->most_val == node->right->most_val) {
                node->most_val = node->left->most_val;
                node->freq_diff = node->left->freq_diff + node->right->freq_diff;
            } else if (node->left->freq_diff > node->right->freq_diff) {
                node->most_val = node->left->most_val;
                node->freq_diff = node->left->freq_diff - node->right->freq_diff;
            } else if (node->left->freq_diff < node->right->freq_diff) {
                node->most_val = node->right->most_val;
                node->freq_diff = node->right->freq_diff - node->left->freq_diff;
            }
            return node;
        }
        pairs query(SegmentTreeNode *cur_node, int s, int e) {
            if (cur_node->start >= s && cur_node->end <= e)
                return {cur_node->most_val, cur_node->freq_diff};
            else if (cur_node->start > e || cur_node->end < s)
                return {0, 0};
            else {
                auto L = query(cur_node->left, s, e);
                auto R = query(cur_node->right, s, e);
                if (L.first == R.first)
                    return {L.first, L.second + R.second};
                else if (L.second > R.second)
                    return {L.first, L.second - R.second};
                else if (L.second < R.second)
                    return {R.first, R.second - L.second};
                else
                    return {0, 0};
            }
        }
    };
    SegmentTree *tree;
    unordered_map<int, vector<int>> num2pos;
public:
    MajorityChecker(vector<int>& arr) {
        tree = new SegmentTree(arr);
        for (int i = 0; i < arr.size(); i++)
            num2pos[arr[i]].push_back(i);
    }

    int query(int left, int right, int threshold) {
        auto [num, freq] = tree->query(tree->root, left, right);
        int l = lower_bound(begin(num2pos[num]), end(num2pos[num]), left) - begin(num2pos[num]);
        int r = upper_bound(begin(num2pos[num]), end(num2pos[num]), right) - begin(num2pos[num]);
        if (r - l >= threshold)
            return num;
        else
            return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> nums{{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> res = s.criticalConnections(4, nums);
    for (auto v: res)
        cout << v[0] << " " << v[1] << endl;
}