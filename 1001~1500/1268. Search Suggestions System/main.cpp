/**
 * Source: twtr.to/ln4QA
 * Date: 2023/11/17
 * Skill:
 * Runtime: 161 ms, faster than 34.18% of C++ online submissions
 * Memory Usage: 218.51 MB, less than 20.02% of C++ online submissions
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
    vector<string> mx[MX];
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode *head = new TrieNode();
        for (auto &s: products) {
            TrieNode *cur = head;
            for (auto &c: s) {
                if (cur->next[c - 'a'] == nullptr) cur->next[c - 'a'] = new TrieNode();
                cur->mx[c - 'a'].push_back(s);
                cur = cur->next[c - 'a'];
            }
        }
        vector<vector<string>> res;
        for (auto &c: searchWord) {
            if (head == nullptr || head->mx[c - 'a'].size() == 0) {
                res.push_back({});
                head = nullptr;
                continue;
            }
            vector<string> ans;
            sort(begin(head->mx[c - 'a']), end(head->mx[c - 'a']));
            for (int i = 0; i < min(3, (int)head->mx[c - 'a'].size()); i++) {
                ans.push_back(head->mx[c - 'a'][i]);
            }
            res.push_back(ans);
            head = head->next[c - 'a'];
        }
        return res;
    }
};


int main() {
    Solution s;
}