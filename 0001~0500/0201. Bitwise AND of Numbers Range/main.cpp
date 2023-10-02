/**
 * Source: ibit.ly/UtbKp
 * Date: 2023/10/2
 * Skill:
 * Runtime: 3 ms, faster than 90.63% of C++ online submissions
 * Memory Usage: 6.44 MB, less than 6.14% of C++ online submissions
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
    int rangeBitwiseAnd(int left, int right) {
        if (left == right)
            return left;
        else
            return rangeBitwiseAnd(left >> 1, right >> 1) << 1;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}