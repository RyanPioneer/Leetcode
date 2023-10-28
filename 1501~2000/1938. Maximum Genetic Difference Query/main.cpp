/**
 * Source: tinyurl.com/ylhoghoa
 * Date: 2023/10/28
 * Skill:
 * Runtime: 705 ms, faster than 66.06% of C++ online submissions
 * Memory Usage: 240.10 MB, less than 93.58% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
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

const int MX = 1e5+1;
const int MX_BIT = 31;

class Solution {
    class TrieNode {
    public:
        TrieNode *next[2];
        int cnt[2] = {0};
    };
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        vector<int> children[MX], res(queries.size());
        int order[MX], root;
        int sz = queries.size(), cur_order = 0;
        for (int i = 0; i < parents.size(); i++) {
            if (parents[i] == -1) root = i;
            else children[parents[i]].push_back(i);
        }
        function<void(int)> dfs;
        dfs = [&](int node) {
            order[node] = cur_order++;
            for (auto i: children[node]) dfs(i);
        };
        dfs(root);
        for (int i = 0; i < sz; i++) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [&](vector<int> &a, vector<int> &b) {
            return order[a[0]] < order[b[0]];
        });
        int idx = 0;
        TrieNode *root_node = new TrieNode();
        function<void(int)> dfs2;
        dfs2 = [&](int node) {
            // cout << node << endl;
            TrieNode *cur = root_node;
            for (int i = MX_BIT; i >= 0; --i) {
                if (((node >> i) & 1) != 0) {
                    cur->cnt[1]++;
                    if (cur->next[1] == nullptr) {
                        cur->next[1] = new TrieNode();
                    }
                    cur = cur->next[1];
                } else {
                    cur->cnt[0]++;
                    if (cur->next[0] == nullptr) {
                        cur->next[0] = new TrieNode();
                    }
                    cur = cur->next[0];
                }
            }
            while (idx < sz && queries[idx][0] == node) {
                int num = queries[idx][1], ret = 0;
                cur = root_node;
                for (int i = MX_BIT; i >= 0; --i) {
                    ret *= 2;
                    int pos = 1 - ((num >> i) & 1);
                    if (cur->cnt[pos] > 0) {
                        ret += 1;
                        cur = cur->next[pos];
                    } else {
                        cur = cur->next[1 - pos];
                    }
                }
                res[queries[idx++][2]] = ret;
            }
            for (auto i: children[node]) dfs2(i);
            cur = root_node;
            for (int i = MX_BIT; i >= 0; --i) {
                if (((node >> i) & 1) != 0) {
                    cur->cnt[1]--;
                    cur = cur->next[1];
                } else {
                    cur->cnt[0]--;
                    cur = cur->next[0];
                }
            }
        };
        dfs2(root);
        return res;
    }
};


int main() {
//    Solution s;
}