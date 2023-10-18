/**
 * Source: twtr.to/K1PUs
 * Date: 2023/10/18
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.26 MB, less than 32.16% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll lo = 1, hi = INT32_MAX, num = lcm((ll)divisor1, (ll)divisor2);
        while (lo < hi) {
            ll mid = (lo + hi) / 2;
            ll num1 = mid - mid / divisor1, num2 = mid - mid / divisor2, num3 = mid - mid / divisor1 - mid / divisor2 + mid / num;
            if (num1 >= uniqueCnt1 && num2 >= uniqueCnt2 && num1 + num2 - num3 >= (ll)uniqueCnt1 + uniqueCnt2)
                hi = mid;
            else
                lo = mid + 1;
        }
        return hi;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}