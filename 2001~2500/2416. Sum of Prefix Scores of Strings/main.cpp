/**
 * Source: https://rb.gy/hixrl
 * Date: 2023/9/1
 * Skill:
 * Runtime: 607 ms, faster than 75.49% of C++ online submissions
 * Memory Usage: 715.66 MB, less than 44.64% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
    class TrieNode {
    public:
        int count;
        TrieNode * children[26];
        TrieNode() {
            count = 0;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        vector<int> res;
        TrieNode *root = new TrieNode();
        for (auto w: words) {
            TrieNode * cur_pos = root;
            for (auto c: w) {
                if (cur_pos->children[c - 'a'] == nullptr)
                    cur_pos->children[c - 'a'] = new TrieNode();
                cur_pos = cur_pos->children[c - 'a'];
                cur_pos->count++;
            }
        }
        for (auto w: words) {
            int cnt = 0;
            TrieNode * cur_pos = root;
            for (auto c: w) {
                cur_pos = cur_pos->children[c - 'a'];
                cnt += cur_pos->count;
            }
            res.push_back(cnt);
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
    vector<int> nums{1,2,5,6,1}, queries{0,3,2,4,1};
}