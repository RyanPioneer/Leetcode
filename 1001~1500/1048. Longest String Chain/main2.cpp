/**
 * Source: t.ly/CsJAv
 * Date: 2023/9/23
 * Skill:
 * Runtime: 87 ms, faster than 59.06% of C++ online submissions
 * Memory Usage: 35.04 MB, less than 34.43% of C++ online submissions
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
    int longestStrChain(vector<string>& words) {
        map<int, unordered_set<string>> len2str;
        for (auto i: words)
            len2str[i.length()].insert(i);
        int res = 0;
        unordered_map<string, int> str2len;
        for (auto p: len2str) {
            for (auto w: p.second) {
                int len = 0;
                for (int i = 0; i < w.length(); i++) {
                    string tmp = w;
                    tmp.erase(i, 1);
                    if (str2len.find(tmp) != str2len.end())
                        len = max(len, str2len[tmp]);
                }
                str2len[w] = len + 1;
                res = max(res, str2len[w]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}