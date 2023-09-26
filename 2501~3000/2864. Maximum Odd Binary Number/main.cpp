/**
 * Source: t.ly/VbOeD
 * Date: 2023/9/24
 * Skill:
 * Runtime: 4 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.41 MB, less than 100.00% of C++ online submissions
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
    string maximumOddBinaryNumber(string s) {
        string res;
        int one_num = 0, sz = s.length();
        for (auto c: s)
            if (c == '1')
                one_num++;
        for (int i = 0; i < sz - 1; i++) {
            if (one_num > 1) {
                res.push_back('1');
                one_num--;
            } else
                res.push_back('0');
        }
        return res + '1';
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