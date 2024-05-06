/**
 * Source: t.ly/1H6F0
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 149 ms, faster than 42.68% of C++ online submissions
 * Memory Usage: 120.59 MB, less than 53.66% of C++ online submissions
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

typedef pair<ll, TrieNode *> PLT;

class Solution {
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        ll res = 0;
        vector<vector<int>> graph(n);
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        function<PLT(int, int)> helper = [&](int cur, int par) {
            TrieNode *root = nullptr;
            for (auto &i: graph[cur]) {
                if (i == par) continue;
                auto [node, num] = helper(i, cur);
                if (root) {
                    TrieNode * t = root, t2 = node;

                }
            }
        };
    }
};