/**
 * Source: ibit.ly/1X9U3
 * Date: 2023/10/1
 * Skill:
 * Runtime: 43 ms, faster than 9.7% of C++ online submissions
 * Memory Usage: 269.78 MB, less than 6.05% of C++ online submissions
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
    string reverseWords(string s) {
        string res, tmp;
        for (int i = 0; i < s.length(); i++) {
            tmp.clear();
            while (i < s.length() && s[i] != ' ')
                tmp.push_back(s[i++]);
            reverse(begin(tmp), end(tmp));
            res = res + tmp;
            if (i < s.length())
                res.push_back(' ');
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}