/*
 * @lc app=leetcode id=3597 lang=cpp
 *
 * [3597] Partition String
 */

// @lc code=start
class TrieNode {
   public:
    TrieNode* next[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};

class Solution {
   public:
    TrieNode* root;
    void addString(string s) {
        TrieNode* cur = root;
        for (char c : s) {
            int index = c - 'a';
            if (!cur->next[index]) {
                cur->next[index] = new TrieNode();
            }
            cur = cur->next[index];
        }
    }
    vector<string> partitionString(string s) {
        vector<string> res;
        root = new TrieNode();
        TrieNode* curPos = root;
        string cur;
        for (auto c : s) {
            cur += c;
            int index = c - 'a';
            if (!curPos->next[index]) {
                res.push_back(cur);
                addString(cur);
                cur.clear();
                curPos = root;
            } else {
                curPos = curPos->next[index];
            }
        }
        return res;
    }
};
// @lc code=end
