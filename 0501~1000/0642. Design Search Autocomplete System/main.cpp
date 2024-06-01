/**
 * Source: t.ly/qa79x
 * Date: 2024/5/29
 * Skill:
 * Ref:
 * Runtime: 257 ms, faster than 91.48% of C++ online submissions
 * Memory Usage: 284.26 MB, less than 50.85% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define MK make_pair
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;
typedef pair<int, string> pis;
const int MX = 1e5+7;


class TrieNode {
public:
    TrieNode *next[27];
    map<int, set<string>> mp;
    int freq;

    TrieNode() {
        For(i,0,26) next[i]=nullptr;
        freq = 0;
    }
};


class AutocompleteSystem {
public:
    TrieNode *root, *cur;
    string curStr;

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();
        cur = root;
        For(i,0,sentences.size()-1) {
            TrieNode *node = root;
            for (auto &c: sentences[i]) {
                int idx = c == ' ' ? 0 : c-'a'+1;
                if (node->next[idx] == nullptr) {
                    node->next[idx] = new TrieNode();
                }
                node = node->next[idx];
                node->mp[times[i]].insert(sentences[i]);
            }
            node->freq = times[i];
        }
    }

    vector<string> input(char c) {
        vector<string> res;
        if (c == '#') {
            cur->freq++;
            TrieNode *node = root;
            for (auto &c: curStr) {
                int idx = c == ' ' ? 0 : c-'a'+1;
                node = node->next[idx];
                if (cur->freq - 1 > 0) {
                    node->mp[cur->freq - 1].erase(curStr);
                }
                node->mp[cur->freq].insert(curStr);
            }
            cur = root;
            curStr.clear();
        } else {
            int idx = c == ' ' ? 0 : c - 'a' + 1;
            if (cur->next[idx] == nullptr) {
                cur->next[idx] = new TrieNode();
            }
            cur = cur->next[idx];
            auto it = cur->mp.rbegin();
            while (res.size() < 3 && it != cur->mp.rend()) {
                for (auto &i: it->second) {
                    res.push_back(i);
                    if (res.size() == 3) break;
                }
                it = next(it);
            }
            curStr.push_back(c);
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */