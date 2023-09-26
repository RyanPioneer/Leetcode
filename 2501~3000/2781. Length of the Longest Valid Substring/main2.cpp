/**
 * Source: t.ly/Gh-FS
 * Date: 2023/9/22
 * Skill:
 * Runtime: TLE
 * Memory Usage:
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= forbidden[i].length <= 10
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
        unordered_map<int, unordered_set<ll>> len2str;
        unordered_map<int, ll> len2cur_str;
        unordered_map<int, ll> len2base;
        ll base = 27;
        for (auto s: forbidden) {
            ll hash = 0, pow = 1;
            for (auto c: s) {
                hash *= base;
                hash += c - 'a' + 1;
                pow *= base;
            }
            len2str[s.length()].insert(hash);
            len2base[s.length()] = pow / base;
        }
        int res = 0, cur_left = 0, sz = word.length();
        for (int i = 0; i < sz; ++i) {
            for (auto k: len2str) {
                if (k.first == i + 1) {
                    ll hash = 0;
                    string sub_str = word.substr(0, k.first);
                    for (auto c: sub_str) {
                        hash *= base;
                        hash += c - 'a' + 1;
                    }
                    len2cur_str[k.first] = hash;
                    if (len2str[k.first].find(hash) != len2str[k.first].end())
                        cur_left = max(cur_left, 1);
                } else if (k.first < i + 1) {
                    len2cur_str[k.first] %= len2base[k.first];
                    len2cur_str[k.first] *= base;
                    len2cur_str[k.first] += word[i] - 'a' + 1;
                    if (len2str[k.first].find(len2cur_str[k.first]) != len2str[k.first].end())
                        cur_left = max(cur_left, i - k.first + 2);
                }
            }
            res = max(res, i - cur_left + 1);
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