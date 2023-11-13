/**
 * Source: t.ly/3GD8X
 * Date: 2023/11/13
 * Skill:
 * Runtime: 2 ms, faster than 58.87% of C++ online submissions
 * Memory Usage: 6.51 MB, less than 8.06% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= p <= 60
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


#define ll long long


class Solution {
    ll mod = 1e9+7;
public:
    int minNonZeroProduct(int p) {
        ll mx = 1, time = 1, n = 1;
        for (int i = 1; i < p; i++) {
            time *= 2;
            n = n * 2 % mod;
            mx = (mx + n) % mod;
        }
        return quickMul((mx - 1) % mod, time - 1) * mx % mod;
    }
    ll quickMul(ll num, ll time) {
        if (time == 0) return 1;
        if (time == 1) return num;
        ll n = quickMul(num * num % mod, time / 2);
        return n * (time % 2 == 0 ? 1 : num) % mod;
    }
};


int main() {
    Solution s;
}