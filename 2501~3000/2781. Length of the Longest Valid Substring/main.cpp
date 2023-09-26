/**
 * Source: t.ly/Gh-FS
 * Date: 2023/9/22
 * Skill:
 * Runtime: WA
 * Memory Usage:
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        ULL hash = 0, base = 27;
        int res = 0, cur_left = 0, sz = word.length();
        unordered_set<ULL> forbidden_hash;
        unordered_map<ULL, ULL> hash2base;
        unordered_map<ULL, int> hash2len;
        for (auto s: forbidden) {
            ULL cur_hash = 0, cur_base = 1;
            for (auto c: s) {
                cur_hash *= base;
                cur_hash += c - 'a' + 1;
                cur_base *= base;
            }
            forbidden_hash.insert(cur_hash);
            hash2base[cur_hash] = cur_base;
            hash2len[cur_hash] = s.length();
        }
        for (int i = 0; i < sz; i++) {
            hash *= base;
            hash += word[i] - 'a' + 1;
            for (auto j: forbidden_hash) {
                if (hash2len[j] > i + 1)
                    continue;
                if (hash2len[j] == i + 1 && j == hash)
                    cur_left = max(cur_left, i - hash2len[j] + 2);
                if (hash2len[j] <= i && (hash - j) % hash2base[j] == 0)
                    cur_left = max(cur_left, i - hash2len[j] + 2);
            }
            res = max(res, i - cur_left + 1);
            cout << cur_left << endl;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
    vector<string> forbidden {"bbbacbcb","bcbaaabacb","abbbbcb","bcbcbac","cbaabbbbbb","bbbbaabcb","cccaaaacaa","cbabaaca","baaabacbb","abcabaacaa"};
    int res = s.longestValidSubstring(word, forbidden);
    cout << res << endl;
}