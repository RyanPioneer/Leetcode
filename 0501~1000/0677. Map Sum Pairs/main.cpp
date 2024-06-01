/**
 * Source: t.ly/mEYEy
 * Date: 2024/5/21
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 10.37 MB, less than 83.66% of C++ online submissions
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


const int MX = 1e3 + 10;

class TrieNode {
public:
    TrieNode *next[26];
    int pre;

    TrieNode() {
        For(i,0,25) next[i]=nullptr;
        pre=0;
    }
};

class MapSum {
    TrieNode *root;
    unordered_map<string, int>mp;

public:
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        TrieNode *node = root;
        for (auto &c: key) {
            int idx = c - 'a';
            if (node->next[idx] == nullptr) {
                node->next[idx] = new TrieNode();
            }
            node = node->next[idx];
            if (mp.find(key) != mp.end()) {
                node->pre -= mp[key];
            }
            node->pre += val;
        }
        mp[key] = val;
    }

    int sum(string prefix) {
        TrieNode *node = root;
        for (auto &c: prefix) {
            int idx = c - 'a';
            if (node->next[idx] == nullptr) {
                return 0;
            }
            node = node->next[idx];
        }
        return node->pre;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */