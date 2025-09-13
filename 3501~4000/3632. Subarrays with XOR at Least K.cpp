/*
 * @lc app=leetcode id=3632 lang=cpp
 *
 * [3632] Subarrays with XOR at Least K
 */

// @lc code=start
#define ll long long
class TrieNode {
   public:
    TrieNode* children[2];
    int count;
    TrieNode() {
        children[0] = children[1] = nullptr;
        count = 0;
    }
};
class Solution {
   public:
    TrieNode* root;
    void add(int num) {
        TrieNode* cur = root;
        for (int i = 0; i < 32; i++) {
            int bit = (num >> (31 - i)) & 1;
            if (!cur->children[bit]) {
                cur->children[bit] = new TrieNode();
            }
            cur = cur->children[bit];
            cur->count++;
        }
    }
    long long countXorSubarrays(vector<int>& nums, int k) {
        root = new TrieNode();
        ll res = 0, presum = 0;
        add(presum);
        for (auto& i : nums) {
            TrieNode* curRoot = root;
            presum ^= i;
            for (int j = 0; j < 32; j++) {
                int pBit = (presum >> (31 - j)) & 1;
                int kBit = (k >> (31 - j)) & 1;
                if (kBit) {
                    curRoot = curRoot->children[1 - pBit];
                } else {
                    if (curRoot->children[1 - pBit]) {
                        res += curRoot->children[1 - pBit]->count;
                    }
                    curRoot = curRoot->children[pBit];
                }
                if (!curRoot) break;
                if (j == 31) {
                    res += curRoot->count;
                }
            }
            add(presum);
        }
        return res;
    }
};
// @lc code=end
