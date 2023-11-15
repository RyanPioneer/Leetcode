/**
 * Source: ibit.ly/iQO1q
 * Date: 2023/11/15
 * Skill:
 * Runtime: 27 ms, faster than 5.14% of C++ online submissions
 * Memory Usage: 9.42 MB, less than 6.10% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1) return 1;
        return 1.0 / n + nthPersonGetsNthSeat(n - 1) * (n - 2) / n;
    }
};


int main() {
    Solution s;
}