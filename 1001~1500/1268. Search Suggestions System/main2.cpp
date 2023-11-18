/**
 * Source: twtr.to/ln4QA
 * Date: 2023/11/18
 * Skill:
 * Runtime: 80 ms, faster than 58.97% of C++ online submissions
 * Memory Usage: 72.70 MB, less than 54.50% of C++ online submissions
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


const int MX = 26;

class TrieNode {
public:
    TrieNode *next[MX];
    bool is_end = false;
};

class Solution {
    int len;
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        len = searchWord.length();
        TrieNode *head = new TrieNode();
        for (auto &s: products) {
            TrieNode *cur = head;
            for (auto &c: s) {
                if (cur->next[c - 'a'] == nullptr) cur->next[c - 'a'] = new TrieNode();
                cur = cur->next[c - 'a'];
            }
            cur->is_end = true;
        }
        string cur = "";
        vector<vector<string>> res;
        for (int i = 0; i < len; i++) {
            cur.push_back(searchWord[i]);
            char c = searchWord[i];
            if (head->next[c - 'a'] == nullptr) {
                for (int j = i; j < len; j++) res.push_back({});
                break;
            }
            head = head->next[c - 'a'];
            vector<string> ans;
            dfs(head, cur, ans);
            res.push_back(ans);
        }
        return res;
    }
    void dfs(TrieNode *cur, string &s, vector<string>& ans) {
        if (ans.size() == 3) return;
        if (cur->is_end == true) {
            ans.push_back(s);
            if (ans.size() == 3) return;
        }
        for (int i = 0; i < MX; i++) {
            if (cur->next[i] != nullptr) {
                s.push_back('a' + i);
                dfs(cur->next[i], s, ans);
                s.pop_back();
                if (ans.size() == 3) return;
            }
        }
    }
};


int main() {
    Solution s;
}