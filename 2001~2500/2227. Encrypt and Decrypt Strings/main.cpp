/**
 * Source: tinyurl.com/25hpz9n7
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 663 ms, faster than 12.05% of C++ online submissions
 * Memory Usage: 188.54 MB, less than 6.02% of C++ online submissions
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

const int MX = 26;

class TrieNode {
public:
    TrieNode *next[MX];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < MX; i++) {
            next[i] = nullptr;
        }
    }
};

class Encrypter {
public:
    TrieNode * root;
    unordered_map<char, string> key2value;
    unordered_map<string, vector<char>> value2key;

    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        root = new TrieNode();
        for (auto &s: dictionary) {
            TrieNode *node = root;
            for (auto &c: s) {
                if (!node->next[c - 'a']) {
                    node->next[c - 'a'] = new TrieNode();
                }
                node = node->next[c - 'a'];
            }
            node->isEnd = true;
        }

        for (int i = 0; i < keys.size(); i++) {
            key2value[keys[i]] = values[i];
            value2key[values[i]].push_back(keys[i]);
        }
    }

    string encrypt(string word1) {
        string res;
        for (auto &c: word1) {
            if (key2value.find(c) == key2value.end()) {
                return "";
            }
            res += key2value[c];
        }
        return res;
    }

    int decrypt(string word2) {
        int len = word2.length(), res = 0;
        queue<pair<TrieNode *, int>> q;
        q.push({root, 0});
        while (!q.empty()) {
            auto [node, pos] = q.front();
            q.pop();
            if (pos == len) {
                if (node->isEnd) res++;
                continue;
            }
            string nxt = word2.substr(pos, 2);
            for (auto &i: value2key[nxt]) {
                if (node->next[i - 'a']) {
                    q.push({node->next[i - 'a'], pos + 2});
                }
            }
        }
        return res;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */