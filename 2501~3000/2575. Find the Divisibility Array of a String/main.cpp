/**
 * Source: t.ly/jehY9
 * Date: 2023/9/23
 * Skill:
 * Runtime: 31 ms, faster than 96.41% of C++ online submissions
 * Memory Usage: 26.77 MB, less than 6.70% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= word.length <= 10 ** 5
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
    vector<int> divisibilityArray(string word, int m) {
        vector<int> res;
        ll cur_num = 0;
        for (int i = 0; i < word.length(); ++i) {
            cur_num = (cur_num * 10 % m + word[i] - '0') % m;
            res.push_back(cur_num == 0);
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