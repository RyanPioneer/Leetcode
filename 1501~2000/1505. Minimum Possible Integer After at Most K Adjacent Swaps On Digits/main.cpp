/**
 * Source: t.ly/YcEZR
 * Date: 2023/11/1
 * Skill:
 * Runtime: 59 ms, faster than 73.17% of C++ online submissions
 * Memory Usage: 21.00 MB, less than 15.45% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e4 * 3 + 1;
typedef pair<int, int> pairs;


class segmentTreeNode {
public:
    int begin;
    int end;
    int mid;
    segmentTreeNode *left, *right;
    int sum;

    segmentTreeNode(int l, int r) : begin(l), end(r) {
        mid = (l + r) / 2;
        left = right = nullptr;
        sum = 0;
    }
};

class segmentTree {
public:
    segmentTreeNode *root;
    void buildTree(int l, int r) {
        root = new segmentTreeNode(l, r);
    }

    segmentTree(int l, int r) {
        buildTree(l, r);
    }

    void update(segmentTreeNode *node, int idx) {
        if (node->begin > idx || node->end < idx) return;
        node->sum++;
        if (node->begin == idx && node->end == idx) {
            return;
        }
        if (idx <= node->mid) {
            if (node->left == nullptr) {
                node->left = new segmentTreeNode(node->begin, node->mid);
            }
            update(node->left, idx);
        } else {
            if (node->right == nullptr) {
                node->right = new segmentTreeNode(node->mid + 1, node->end);
            }
            update(node->right, idx);
        }
    }

    int query_range(segmentTreeNode *node, int l, int r) {
        if (node == nullptr) return 0;
        if (node->begin > r || node->end < l) return 0;
        if (node->begin >= l && node->end <= r) return node->sum;
        return query_range(node->left, l, r) + query_range(node->right, l, r);
    }
};

class Solution {
public:
    string minInteger(string num, int k) {
        vector<pairs> nums;
        for (int i = 0; i < num.size(); i++) {
            nums.push_back({num[i] - '0', i});
        }
        sort(nums.begin(), nums.end());
        string res;
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        int used[MX] = {0}, sz = num.length(), cost;
        segmentTree *tree = new segmentTree(0, nums.size());
        for (int i = 0; i < num.size() && k > 0; i++) {
            while (!pq.empty() && (cost = pq.top().first - tree->query_range(tree->root, 0, pq.top().first)) <= k) {
                res += to_string(pq.top().second);
                k -= cost;
                used[pq.top().first] = 1;
                tree->update(tree->root, pq.top().first);
                pq.pop();
            }
            cost = nums[i].second - tree->query_range(tree->root, 0, nums[i].second);
            if (cost <= k) {
                res += to_string(nums[i].first);
                k -= cost;
                used[nums[i].second] = 1;
                tree->update(tree->root, nums[i].second);
            } else {
                pq.push({nums[i].second, nums[i].first});
            }
        }
        for (int i = 0; i < sz; i++) {
            if (used[i] == 0) res += num[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    string res = s.minInteger("294984148179", 11);
    cout << res << endl;
    vector<int> nums{1,2,3,4};
}