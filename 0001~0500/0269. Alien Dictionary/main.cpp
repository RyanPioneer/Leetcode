/**
 * Source: t.ly/K71Hp
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 49.18% of C++ online submissions
 * Memory Usage: 12.54 MB, less than 45.21% of C++ online submissions
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
    TrieNode* next[MX];
    int lastIdx;
    TrieNode() {
        for (int i = 0; i < MX; i++) next[i] = nullptr;
        lastIdx = -1;
    }
};

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res;
        vector<vector<int>> graph(MX);
        int inDegree[MX] = {0};
        TrieNode *root = new TrieNode();
        unordered_set<char> Set;

        for (auto &w: words) {
            TrieNode *node = root;
            bool found = false;
            for (auto &c: w) {
                Set.insert(c);
                int idx = c - 'a';
                if (node->next[idx] != nullptr && node->lastIdx != idx) return res;
                if (node->next[idx] == nullptr) {
                    if (!found) {
                        found = true;
                        for (int i = 0; i < MX; i++) {
                            if (node->next[i] == nullptr) continue;
                            graph[i].push_back(idx);
                            inDegree[idx]++;
                        }
                    }
                    node->next[idx] = new TrieNode();
                    node->lastIdx = idx;
                }
                node = node->next[idx];
            }
            for (int i = 0; i < MX; i++) {
                if (node->next[i] != nullptr) return res;
            }
        }

        queue<int> q;

        for (int i = 0; i < MX; i++) {
            if (inDegree[i] == 0 && Set.find('a' + i) != Set.end()) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back('a' + cur);
            for (auto &i: graph[cur]) {
                inDegree[i]--;
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }

        return res.length() == Set.size() ? res : "";
    }
};