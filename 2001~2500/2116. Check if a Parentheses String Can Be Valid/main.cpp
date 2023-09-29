/**
 * Source: ibit.ly/A2UkK
 * Date: 2023/9/29
 * Skill:
 * Runtime: 86 ms, faster than 81.59% of C++ online submissions
 * Memory Usage: 27.37 MB, less than 45.54% of C++ online submissions
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
    bool canBeValid(string s, string locked) {
        int upper = 0, lower = 0;
        for (int i = 0; i < s.length(); i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    lower++; upper++;
                } else {
                    lower--; upper--;
                }
            } else {
                lower--; upper++;
            }
            if (lower < 0)
                lower += 2;
            if (upper < 0)
                return false;
        }
        return lower == 0;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}