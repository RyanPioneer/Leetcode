/**
 * Source: ibit.ly/tNMiD
 * Date: 2024/6/28
 * Skill:
 * Ref:
 * Runtime: 408 ms, faster than 23.46% of C++ online submissions
 * Memory Usage: 282.18 MB, less than 5.03% of C++ online submissions
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
const int MX = 32;


class TrieNode {
public:
    TrieNode *next[2];
    int idx;

    TrieNode(int id) {
        for (int i = 0; i < 2; i++) {
            next[i] = nullptr;
            idx = id;
        }
    }
};


class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();
        TrieNode *root = new TrieNode(-1);
        for (int i = 0; i < n; i++) {
            TrieNode *cur = root;
            for (int idx = 0; idx < MX; idx++) {
                if (i + idx >= n) break;
                int bit = s[i + idx] == '0' ? 0 : 1;
                if (!cur->next[bit]) {
                    cur->next[bit] = new TrieNode(i);
                }
                cur = cur->next[bit];
            }
        }

        vector<vector<int>> res;
        for (auto &q: queries) {
            TrieNode *cur = root;
            q[0] ^= q[1];
            if (q[0] == 0) {
                if (cur->next[0]) {
                    res.push_back({cur->next[0]->idx, cur->next[0]->idx});
                } else {
                    res.push_back({-1, -1});
                }
            } else {
                int len = 0;
                stack<int> st;
                while (q[0]) {
                    len++;
                    st.push(q[0] & 1);
                    q[0] >>= 1;
                }
                while (!st.empty()) {
                    if (cur->next[st.top()]) {
                        cur = cur->next[st.top()];
                        st.pop();
                    } else {
                        break;
                    }
                }
                if (st.empty()) {
                    res.push_back({cur->idx, cur->idx + len - 1});
                } else {
                    res.push_back({-1, -1});
                }
            }
        }
        return res;
    }
};