/**
 * Source: https://rb.gy/itzx6
 * Date: 2023/9/10
 * Skill:
 * Runtime: 584 ms, faster than 91.25% of C++ online submissions
 * Memory Usage: 180.32 MB, less than 44.00% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
    class TrieNode {
    public:
        TrieNode *next[2];
    };
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        TrieNode *root = new TrieNode();
        for (auto n: nums) {
            TrieNode *node = root;
            for (int i = 31; i >= 0; i--) {
                if (node->next[((n >> i) & 1)] == NULL)
                    node->next[((n >> i) & 1)] = new TrieNode();
                node = node->next[((n >> i) & 1)];
            }
            TrieNode *node = root;
            int num = 0;
            for (int i = 31; i >= 0; i--) {
                num *= 2;
                if (node->next[1 - ((n >> i) & 1)] == NULL)
                    node = node->next[((n >> i) & 1)];
                else {
                    node = node->next[1 - ((n >> i) & 1)];
                    num += 1;
                }
            }
            res = max(res, num);
        }
        return res;
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
    string ss = "level";
}