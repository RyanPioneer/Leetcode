/**
 * Source: ibit.ly/guYOU
 * Date: 2023/10/30
 * Skill:
 * Runtime: 526 ms, faster than 20.00% of C++ online submissions
 * Memory Usage: 197.85 MB, less than 20.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e5+1;

#define ll long long

ll mod = 1e9+7;

class SegmentTreeNode {
public:
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    int begin;
    int end;
    int mid;
    ll sum;
    ll add_time;
    ll range;

    SegmentTreeNode(int b, int e) {
        begin = b;
        end = e;
        range = end - begin + 1;
        mid = (b + e) / 2;
        sum = 0;
        add_time = 0;
        left = nullptr;
        right = nullptr;
    }

    SegmentTreeNode(int b, int e, int s, int a, SegmentTreeNode *l, SegmentTreeNode *r) {
        begin = b;
        end = e;
        mid = (b + e) / 2;
        sum = s;
        add_time = a;
        left = l;
        right = r;
    }
};


class SegmentTree {
public:
    SegmentTreeNode *root;
    SegmentTree() {
        root = new SegmentTreeNode(0, pow(10, 5) + 1);
    }
    void update_delta(SegmentTreeNode * node, int l, int r) {
        if (node == nullptr)
            return;
        if (r < node->begin || l > node->end)
            return;
        if (node->begin == node->end) {
            node->sum++;
            return;
        }
        if (l <= node->begin && r >= node->end) {
            node->add_time++;
            return;
        }
        if (l <= node->mid) {
            if (node->left == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->begin, node->mid) ;
                node->left = n;
            }
            update_delta(node->left, l, r);
        }
        if (r > node->mid) {
            if (node->right == nullptr) {
                SegmentTreeNode *n = new SegmentTreeNode(node->mid + 1, node->end) ;
                node->right = n;
            }
            update_delta(node->right, l, r);
        }
        node->sum += min(node->end, r) - max(node->begin, l) + 1;
    }

    ll query_range_sum(SegmentTreeNode * node, int l, int r) {
        if (node->begin > r || node->end < l || (node->sum == 0 && node->add_time == 0) || l > r)
            return 0;
        if (node->begin >= l && node->end <= r) {
            return node->sum + node->range * node->add_time;
        }

        ll num = 0;
        if (node->left == nullptr) {
            SegmentTreeNode *n = new SegmentTreeNode(node->begin, node->mid) ;
            node->left = n;
        }
        node->left->add_time += node->add_time;
        num += query_range_sum(node->left, l, r);

        if (node->right == nullptr) {
            SegmentTreeNode *n = new SegmentTreeNode(node->mid + 1, node->end) ;
            node->right = n;
        }
        node->right->add_time += node->add_time;
        num += query_range_sum(node->right, l, r);

        node->sum += node->range * node->add_time;
        node->add_time = 0;
        return num;
    }
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        SegmentTree *tree = new SegmentTree();
        ll res = 0, cur_num = 0;
        int last_index[MX] = {0};
        for (int i = 1; i <= nums.size(); i++) {
            int idx = last_index[nums[i - 1]];
            ll n = tree->query_range_sum(tree->root, idx + 1, i - 1);
            cur_num = (cur_num + (i - idx) + n * 2) % mod;
            res = (res + cur_num) % mod;
            tree->update_delta(tree->root, idx + 1, i);
            last_index[nums[i - 1]] = i;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}