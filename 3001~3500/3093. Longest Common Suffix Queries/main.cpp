/**
 * Source: is.gd/Vu6HeO
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 344 ms, faster than 88.93% of C++ online submissions
 * Memory Usage: 819.79 MB, less than 43.10% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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


class TrieNode {
public:
    TrieNode *next[26];
    int idx;
    TrieNode() {
        idx = -1;
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};


class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> res, len(wordsContainer.size());
        TrieNode *root = new TrieNode();
        int zero = wordsContainer.size() - 1;
        for (int i = wordsContainer.size() - 1; i >= 0; i--) {
            string &s = wordsContainer[i];
            len[i] = s.length();
            if (len[i] <= len[zero]) zero = i;
            TrieNode *node = root;
            for (int j = s.length() - 1; j >= 0; j--) {
                if (node->next[s[j] - 'a'] == nullptr) {
                    node->next[s[j] - 'a'] = new TrieNode();
                }
                node = node->next[s[j] - 'a'];
                if (node->idx == -1 || len[node->idx] >= len[i]) node->idx = i;
            }
        }
        for (auto &s: wordsQuery) {
            TrieNode *node = root;
            res.push_back(zero);
            for (int j = s.length() - 1; j >= 0; j--) {
                if (node->next[s[j] - 'a'] == nullptr) {
                    break;
                }
                node = node->next[s[j] - 'a'];
                res.back() = node->idx;
            }
        }
        return res;
    }
};