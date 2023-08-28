/**
 * Source: https://rb.gy/q6yef
 * Date: 2023/8/28
 * Skill:
 * Runtime: 594 ms, faster than 40.81% of C++ online submissions
 * Memory Usage: 236.38 MB, less than 12.47% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;


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
        root = new SegmentTreeNode(0, pow(10, 9) + 1, 0);
    }
    void update_delta(SegmentTreeNode * node, int pos, int delta) {
        if (node == nullptr)
            return;
        if (pos < node->begin || pos > node->end)
            return;
        if (pos == node->begin && pos == node->end) {
            node->val = max(node->val, delta);
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
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<int> res(queries.size(), -1);
        SegmentTree *tree = new SegmentTree();
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] > b[0];
        });

        vector<vector<int>> nums;
        for (int i = 0; i < nums1.size(); i++) {
            vector<int> n;
            n.push_back(nums1[i]);
            n.push_back(nums2[i]);
            nums.push_back(n);
        }
        sort(nums.begin(), nums.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] > b[0];
        });
        int pos = 0;
        for (int i = 0; i < queries.size(); i++) {
            while (pos < nums.size() && nums[pos][0] >= queries[i][0]) {
                tree->update_delta(tree->root, nums[pos][1], nums[pos][0] + nums[pos][1]);
                pos++;
            }
            int num = tree->query_range_max(tree->root, queries[i][1], pow(10, 9));
            if (num > 0)
                res[queries[i][2]] = num;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums1{72,88,53,63,95,46};
    vector<int> nums2{78,56,35,72,56,63};
    vector<vector<int>> queries;
    vector<int> n1{86, 86}, n2{24, 8};
    queries.push_back(n1);
    queries.push_back(n2);
//    queries.push_back(n3);
    vector<int> res = s.maximumSumQueries(nums1, nums2, queries);
    for (auto i: res) {
        cout << i << endl;
    }
}

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();