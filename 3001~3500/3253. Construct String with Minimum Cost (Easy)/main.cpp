/**
 * Source: ibit.ly/_zOIW
 * Date: 2024/10/3
 * Skill:
 * Ref:
 * Runtime: 98 ms, faster than 41.00% of C++ online submissions
 * Memory Usage: 260.38 MB, less than 37.00% of C++ online submissions
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

class TrieNode {
public:
    TrieNode *next[26];
    int cost;
    TrieNode() : cost(0) {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
    }
};


class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode *head = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode *cur = head;
            for (int j = words[i].size() - 1; j >= 0; j--) {
                int idx = words[i][j] - 'a';
                if (!cur->next[idx]) {
                    cur->next[idx] = new TrieNode();
                }
                cur = cur->next[idx];
            }
            if (!cur->cost) cur->cost = costs[i];
            else cur->cost = min(cur->cost, costs[i]);
        }

        vector<int> res(target.length() + 1, INT32_MAX);
        res[0] = 0;
        for (int idx = 1; idx <= target.length(); idx++) {
            TrieNode *cur = head;
            for (int pos = idx; pos > 0; pos--) {
                int index = target[pos-1] - 'a';
                if (!cur->next[index]) break;
                cur = cur->next[index];
                if (cur->cost && res[pos - 1] != INT32_MAX) {
                    res[idx] = min(res[idx], res[pos - 1] + cur->cost);
                }
            }
        }
        return res.back() == INT32_MAX ? -1 : res.back();
    }
};