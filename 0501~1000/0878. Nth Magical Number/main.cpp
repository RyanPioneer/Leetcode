/**
 * Source: is.gd/N3OAZ2
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 56.32% of C++ online submissions
 * Memory Usage: 6.34 MB, less than 38.95% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#define ll long long
ll mod = 1e9+7;


class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int c = lcm(a, b);
        ll left = min(a, b), right = LLONG_MAX / 2;
        while (right > left) {
            ll mid = (left + right) / 2;
            ll num = mid / a + mid / b - mid / c;
            if (num >= n) right = mid;
            else left = mid + 1;
        }
        return left % mod;
    }
};