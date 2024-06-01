/**
 * Source: t.ly/qvb9w
 * Date: 2024/5/21
 * Skill:
 * Ref:
 * Runtime: 125 ms, faster than 94.55% of C++ online submissions
 * Memory Usage: 69.99 MB, less than 59.09% of C++ online submissions
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
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)
typedef pair<int, int> PII;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Trienode {
public:
    Trienode *next[26];
    int cnt, pre;

    Trienode() {
        For(i,0,25) next[i]=nullptr;
        cnt=0;
        pre=0;
    }
};


class Trie {
    Trienode *root;
public:
    Trie() {
        root = new Trienode();
    }

    void insert(string word) {
        Trienode *node = root;
        for (auto &c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                node->next[idx] = new Trienode();
            }
            node = node->next[idx];
            node->pre++;
        }
        node->cnt++;
    }

    int countWordsEqualTo(string word) {
        Trienode *node = root;
        for (auto &c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                return 0;
            }
            node = node->next[idx];
        }
        return node->cnt;
    }

    int countWordsStartingWith(string prefix) {
        Trienode *node = root;
        for (auto &c: prefix) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                return 0;
            }
            node = node->next[idx];
        }
        return node->pre;
    }

    void erase(string word) {
        Trienode *node = root;
        for (auto &c: word) {
            int idx = c - 'a';
            if (!node->next[idx]) {
                return;
            }
            node->pre--;
            node = node->next[idx];
        }
        node->pre--;
        node->cnt--;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */