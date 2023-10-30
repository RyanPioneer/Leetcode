/**
 * Source: ibit.ly/bc81D
 * Date: 2023/10/30
 * Skill:
 * Runtime: 1264 ms, faster than 5.25% of C++ online submissions
 * Memory Usage: 202.71 MB, less than 5.54% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
    class TrieNode {
    public:
        TrieNode *next[2];
        int cnt[2] = {0};
    };
public:
    int countPairs(vector<int>& nums, int low, int high) {
        TrieNode *root = new TrieNode();
        string low_string = bitset<32>( low - 1).to_string(), high_string = bitset<32>( high ).to_string();
        reverse(begin(low_string), end(low_string));
        reverse(begin(high_string), end(high_string));
        function<int(TrieNode *, string &, string &)> dfs;
        dfs = [&](TrieNode *node, string &target, string &num) {
            int bit1 = target.back() - '0', bit2 = num.back() - '0', count = 0;
            target.pop_back();
            num.pop_back();
            int cur = bit1 ^ bit2;
            int r = 1 - cur;
            if (bit1 == 1) count += node->cnt[r];
            if (num.empty() || node->cnt[cur] == 0) {
                count += node->cnt[cur];
                return count;
            }
            return count + dfs(node->next[cur], target, num);
        };
        function<void(TrieNode *, string &)> insert;
        insert = [&](TrieNode * node, string& s) {
            int bit = s.back() - '0';
            s.pop_back();
            node->cnt[bit]++;
            if (node->cnt[bit] == 1) {
                node->next[bit] = new TrieNode();
            }
            if (!s.empty()) {
                insert(node->next[bit], s);
            }
        };

        int res = 0;
        for (auto i: nums) {
            string bit_s = bitset<32>( i ).to_string();
            reverse(begin(bit_s), end(bit_s));
            string hi = high_string, lo = low_string, bit_s2 = bit_s, bit_s3 = bit_s;
            res += dfs(root, hi, bit_s) - dfs(root, lo, bit_s2);
            insert(root, bit_s3);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}