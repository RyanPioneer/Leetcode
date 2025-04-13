/**
 * Source: tinyurl.com/2xjbnzl3
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime:
 * Memory Usage: MLE
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MX = 500;

class TrieNode {
   public:
    TrieNode* children[26];
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
   public:
    int countDistinct(string s) {
        int res = 0;
        TrieNode* root = new TrieNode();
        for (int i = 0; i < s.size(); i++) {
            TrieNode* cur = root;
            for (int j = i; j < s.size(); j++) {
                if (cur->children[s[j] - 'a'] == nullptr) {
                    cur->children[s[j] - 'a'] = new TrieNode();
                    res++;
                }
                cur = cur->children[s[j] - 'a'];
            }
        }
        return res;
    }
};
