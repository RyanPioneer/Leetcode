/**
 * Source: ibit.ly/bc81D
 * Date: 2023/10/30
 * Skill:
 * Runtime: 146 ms, faster than 92.71% of C++ online submissions
 * Memory Usage: 71.59 MB, less than 83.09% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

const int MX = 15;

class Solution {
    class TrieNode {
    public:
        TrieNode *next[2];
        int cnt[2] = {0};
    };
public:
    int countPairs(vector<int>& nums, int lo, int hi) {
        TrieNode *root = new TrieNode();
        function<int(TrieNode *, int, int)> countSmallerThan;
        countSmallerThan = [](TrieNode *node, int target, int num) {
            int res = 0;
            for (int i = MX; i >= 0; i--) {
                int bit1 = ((target >> i) & 1), bit2 = ((num >> i) & 1);
                int cur = (bit1 ^ bit2);
                if (bit1 == 1) res += node->cnt[1 - cur];
                if (node->cnt[cur] > 0) {
                    if (i == 0) res += node->cnt[cur];
                    node = node->next[cur];
                } else {
                    break;
                }
            }
            return res;
        };
        function<void(TrieNode *, int)> insert;
        insert = [&](TrieNode * node, int num) {
            for (int i = MX; i >= 0; i--) {
                int bit = ((num >> i) & 1);
                node->cnt[bit]++;
                if (node->cnt[bit] == 1) {
                    node->next[bit] = new TrieNode();
                }
                node = node->next[bit];
            }
        };

        int res = 0;
        for (auto i: nums) {
            res += countSmallerThan(root, hi, i) - countSmallerThan(root, lo - 1, i);
            insert(root, i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}