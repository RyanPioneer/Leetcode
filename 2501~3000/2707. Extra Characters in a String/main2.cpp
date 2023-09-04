/**
 * Source: https://rb.gy/85e1h
 * Date: 2023/9/2
 * Skill: If you can use unordered_set, don't use set!
 * Runtime: 47 ms, faster than 99.52% of C++ online submissions
 * Memory Usage: 105.99 MB, less than 28.31% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= s.length <= 50
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
        class TrieNode {
        public:
            TrieNode *next[26];
            bool is_word;
            TrieNode () {
                is_word = false;
                for (int i = 0; i < 26; i++)
                    next[i] = NULL;
            }
        };
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        TrieNode *root = new TrieNode();
        for (auto i: dictionary) {
            TrieNode * cur_pos = root;
            int length = i.length();
            for (int j = length - 1; j >= 0; j--) {
                if (cur_pos->next[i[j] - 'a'] == NULL)
                    cur_pos->next[i[j] - 'a'] = new TrieNode();
                cur_pos = cur_pos->next[i[j] - 'a'];
            }
            cur_pos->is_word = true;
        }

        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        for (int i = 0; i < sz; i++) {
            dp[i + 1] = dp[i] + 1;
            TrieNode * cur_pos = root;
            for (int j = i; j >= 0; j--) {
                if (cur_pos->next[s[j] - 'a'] == NULL)
                    break;
                cur_pos = cur_pos->next[s[j] - 'a'];
                if (cur_pos->is_word)
                    dp[i + 1] = min(dp[i + 1], dp[j]);
            }
        }
        return dp[sz];
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> nums{1,3,2};
}