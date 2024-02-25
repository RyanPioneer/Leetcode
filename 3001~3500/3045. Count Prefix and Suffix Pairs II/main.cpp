/**
 * Source: is.gd/50LUWMe
 * Date: 2024/2/24
 * Skill:
 * Ref:
 * Runtime: 369 ms, faster than 74.45% of C++ online submissions
 * Memory Usage: 661.28 MB, less than 10.15% of C++ online submissions
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
    int cnt;

    TrieNode() : cnt(0) {
        for (int i = 0; i < 26; i++) next[i] = nullptr;
    }
};


class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        TrieNode *head = new TrieNode();
        ll res = 0;
        for (auto &w: words) {
            vector<int> v = preprocess(w);
            stack<int> lens;
            lens.push(w.length());
            int i = v.back();
            while (i > 0) {
                lens.push(i);
                i = v[i - 1];
            }
            TrieNode *cur = head;
            int cur_len = 0;
            for (auto &c: w) {
                if (lens.empty() || cur->next[c - 'a'] == nullptr) break;
                cur = cur->next[c - 'a'];
                cur_len++;
                if (cur_len == lens.top()) {
                    lens.pop();
                    res += cur->cnt;
                }
            }
            cur = head;
            for (auto &c: w) {
                if (cur->next[c - 'a'] == nullptr) cur->next[c - 'a'] = new TrieNode();
                cur = cur->next[c - 'a'];
            }
            cur->cnt++;
        }
        return res;
    }
    vector<int> preprocess(string &s) {
        int len = s.length();
        vector<int> v(len, 0);
        for (int i = 1; i < len; i++) {
            int prev = v[i - 1];
            while (prev > 0 && s[i] != s[prev]) prev = v[prev - 1];
            v[i] = prev + (s[i] == s[prev]);
        }
        return v;
    }
};