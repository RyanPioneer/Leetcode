/**
 * Source: t.ly/Gh-FS
 * Date: 2023/9/22
 * Skill:
 * Runtime: 431 ms, faster than 75.56% of C++ online submissions
 * Memory Usage: 122.91 MB, less than 65.51% of C++ online submissions
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
        unordered_set<string> forbidden_set;
        for (auto s: forbidden)
            forbidden_set.insert(s);
        int res = 0, left = 0, sz = word.length();
        for (int i = 0; i < sz; ++i) {
            for (int j = max(left, i - 9); j <= i; ++j) {   // ! key: int j = max(left, i - 9)
                if (forbidden_set.find(word.substr(j, i - j + 1)) != forbidden_set.end())
                    left = max(left, j + 1);
            }
            res = max(res, i - left + 1);
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