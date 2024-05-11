/**
 * Source: t.ly/1H6F0
 * Date: 2024/5/7
 * Skill:
 * Ref:
 * Runtime: 223 ms, faster than 77.78% of C++ online submissions
 * Memory Usage: 76.52 MB, less than 66.67% of C++ online submissions
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
const int MX = 5e4+2;

class TrieNode {
public:
    TrieNode *next[2];
    TrieNode() {
        for (int i = 0; i < 2; i++) {
            next[i] = nullptr;
        }
    }
};


class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        TrieNode *root = new TrieNode();
        ll res = 0;
        vector<vector<int>> graph(n);
        vector<ll> total(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<ll(int, int)> dfs1 = [&](int cur, int par) {
            total[cur] = values[cur];
            for (auto &i: graph[cur]) {
                if (i == par) continue;
                total[cur] += dfs1(i, cur);
            }
            return total[cur];
        };

        function<void(ll)> addNum = [&](ll num) {
            TrieNode *node = root;
            for (int i = 62; i >= 0; i--) {
                if ((num >> i) & 1) {
                    if (!node->next[1]) {
                        node->next[1] = new TrieNode();
                    }
                    node = node->next[1];
                } else {
                    if (!node->next[0]) {
                        node->next[0] = new TrieNode();
                    }
                    node = node->next[0];
                }
            }
        };

        function<void(ll)> updateRes = [&](ll num) {
            if (!root->next[0] && !root->next[1]) return;
            TrieNode *node = root;
            ll localRes = 0;
            for (int i = 62; i >= 0; i--) {
                if ((num >> i) & 1) {
                    if (node->next[0]) {
                        localRes += 1ll << i;
                        node = node->next[0];
                    } else {
                        node = node->next[1];
                    }
                } else {
                    if (node->next[1]) {
                        localRes += 1ll << i;
                        node = node->next[1];
                    } else {
                        node = node->next[0];
                    }
                }
            }
            res = max(localRes, res);
        };

        function<void(int, int)> dfs2 = [&](int cur, int par) {
            updateRes(total[cur]);
            for (auto &i: graph[cur]) {
                if (i == par) continue;
                dfs2(i, cur);
                addNum(total[i]);
            }
        };

        dfs1(0, -1);
        dfs2(0, -1);
        return res;
    }
};