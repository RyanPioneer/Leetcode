/**
 * Source: ibit.ly/VrA2E
 * Date: 2023/10/8
 * Skill:
 * Runtime: 4 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 6.22 MB, less than 100.00% of C++ online submissions
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
    int differenceOfSums(int n, int m) {
        int num1 = n * (n + 1) / 2;
        int num2 = (m + m * (n / m)) * (n / m);
        return num1 - num2;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}