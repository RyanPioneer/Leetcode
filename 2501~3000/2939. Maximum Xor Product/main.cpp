/**
 * Source: twtr.to/hbAYO
 * Date: 2023/11/20
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.34 MB, less than 16.67% of C++ online submissions
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

#define ll long long


class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        ll mod = 1e9+7;
        for (int i = n - 1; i >= 0; i--) {
            ll num = (1ll << i);
            int a_bit = ((a >> i) & 1), b_bit = ((b >> i) & 1);
            if (a_bit == b_bit){
                a |= num;
                b |= num;
            } else if (a > b) {
                b |= num;
                if (a_bit == 1) a -= num;
            } else {
                a |= num;
                if (b_bit == 1) b -= num;
            }
        }
        return (a % mod) * (b % mod) % mod;
    }
};