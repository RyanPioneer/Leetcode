/**
 * Source: ibit.ly/zMxGt
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 371 ms, faster than 75.90% of C++ online submissions
 * Memory Usage: 234.08 MB, less than 59.94% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
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
const int charNum = 26;


class TrieNode {
public:
    TrieNode *next[charNum];
    TrieNode() {
        for (int i = 0; i < charNum; i++) {
            next[i] = nullptr;
        }
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        TrieNode *root = new TrieNode();

        for (string& word : words) {
            TrieNode *cur = root;
            for (auto &c: word) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = new TrieNode();
                }
                cur = cur->next[c - 'a'];
            }
        }

        int n = target.size();
        vector<int> dp(n + 1, INT32_MAX/4);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            TrieNode *cur = root;
            for (int j = i; j <= n; ++j) {
                if (cur->next[target[j-1] - 'a'] == nullptr) {
                    break;
                }
                cur = cur->next[target[j-1] - 'a'];
                dp[j] = min(dp[j], dp[i-1] + 1);
            }
        }
        return dp[n] == INT32_MAX/4 ? -1 : dp[n];
    }
};
