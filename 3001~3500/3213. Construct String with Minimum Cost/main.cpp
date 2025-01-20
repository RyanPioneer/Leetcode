/**
 * Source: ibit.ly/80tnQ
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: TLE
 * Memory Usage: 
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= target.length <= 5 * 10 ** 4
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
    bool isEnd;
    int cost;
    TrieNode() {
        for (int i = 0; i < charNum; i++) {
            next[i] = nullptr;
        }
        isEnd = false;
        cost = INT32_MAX;
    }
};

class Solution {
public:
    int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        TrieNode *root = new TrieNode();

        for (int i = 0; i < words.size(); ++i) {
            TrieNode *cur = root;
            for (auto &c: words[i]) {
                if (cur->next[c - 'a'] == nullptr) {
                    cur->next[c - 'a'] = new TrieNode();
                }
                cur = cur->next[c - 'a'];
            }
            cur->isEnd = true;
            cur->cost = min(costs[i], cur->cost);
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
                if (cur->isEnd) {
                    dp[j] = min(dp[j], dp[i-1] + cur->cost);
                }
            }
        }
        return dp[n] == INT32_MAX/4 ? -1 : dp[n];
    }
};
