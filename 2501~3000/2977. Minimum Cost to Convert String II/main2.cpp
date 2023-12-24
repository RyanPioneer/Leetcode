/**
 * Source: is.gd/SiWts8
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 655 ms, faster than 10.00% of C++ online submissions
 * Memory Usage: 316.58 MB, less than 10.00% of C++ online submissions
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
const int MX = 201;


class TrieNode {
public:
    TrieNode *next[26];
    int idx;
    TrieNode() {
        fill(next, next + 26, nullptr);
        idx = -1;
    }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        TrieNode *root = new TrieNode();
        unordered_set<string> strs;
        unordered_map<string, int> str2id;
        for (auto &s: original) reverse(begin(s), end(s));
        for (auto &s: changed) reverse(begin(s), end(s));
        strs.insert(begin(original), end(original));
        strs.insert(begin(changed), end(changed));
        int id = 0;
        for (auto &s: strs) {
            TrieNode *cur = root;
            for (auto &c: s) {
                int pos = c - 'a';
                if (cur->next[pos] == nullptr) cur->next[pos] = new TrieNode();
                cur = cur->next[pos];
            }
            cur->idx = id++;
            str2id[s] = cur->idx;
        }

        ll dis[MX][MX];
        fill(dis[0], dis[MX - 1] + MX, LLONG_MAX / 2);
        for (int i = 0; i < id; i++) dis[i][i] = 0;
        for (int i = 0; i < SZ(original); i++) {
            dis[str2id[original[i]]][str2id[changed[i]]] = min(dis[str2id[original[i]]][str2id[changed[i]]], (ll)cost[i]);
        }
        for (int i = 0; i < id; i++) {
            for (int j = 0; j < id; j++) {
                for (int k = 0; k < id; k++) {
                    dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
            }
        }

        source = "#" + source;
        target = "#" + target;
        ll dp[1001];
        fill(dp, dp + 1001, LLONG_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i < source.length(); i++) {
            if (source[i] == target[i]) dp[i] = dp[i - 1];
            TrieNode *s = root, *t = root;
            for (int j = i; j >= 1; j--) {
                int pos1 = source[j] - 'a', pos2 = target[j] - 'a';
                if (s->next[pos1] == nullptr) break;
                s = s->next[pos1];
                if (t->next[pos2] == nullptr) break;
                t = t->next[pos2];
                if (s->idx != -1 && t->idx != -1) {
                    dp[i] = min(dp[i], dp[j - 1] + dis[s->idx][t->idx]);
                }
            }
        }
        return dp[source.length() - 1] < LLONG_MAX / 2 ? dp[source.length() - 1] : -1;
    }
};