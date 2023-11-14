/**
 * Source: t.ly/Kvjwa
 * Date: 2023/11/14
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.24 MB, less than 68.41% of C++ online submissions
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
    int brokenCalc(int startValue, int target) {
        if (startValue >= target) return startValue - target;
        else if (target % 2 == 1) return brokenCalc(startValue, target + 1) + 1;
        else return brokenCalc(startValue, target / 2) + 1;
    }
};


int main() {
    Solution s;
}