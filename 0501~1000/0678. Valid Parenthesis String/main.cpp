/**
 * Source: ibit.ly/GITEf
 * Date: 2023/9/29
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.43 MB, less than 28.09% of C++ online submissions
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
    bool checkValidString(string s) {
        int lower = 0, upper = 0;
        for (auto c: s) {
            if (c == '(') {
                lower++; upper++;
            } else if (c == ')') {
                lower--; upper--;
            } else {
                lower--; upper++;
            }
            if (upper < 0)
                return false;
            if (lower < 0)
                lower++;
        }
        return lower == 0;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}