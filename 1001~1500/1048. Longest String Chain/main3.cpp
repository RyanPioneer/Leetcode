/**
 * Source: t.ly/CsJAv
 * Date: 2023/9/23
 * Skill:
 * Runtime: 57 ms, faster than 96.55% of C++ online submissions
 * Memory Usage: 17.09 MB, less than 51.45% of C++ online submissions
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
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        int res = 0;
        unordered_map<string, int> str2len;
        for (auto& w: words) {
            str2len[w] = 1;
            for (int i = 0; i < w.length(); i++) {
                string tmp = w.substr(0, i) + w.substr(i + 1);
                if (str2len.find(tmp) != str2len.end())
                    str2len[w] = max(str2len[w], str2len[tmp] + 1);
            }
            res = max(res, str2len[w]);
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