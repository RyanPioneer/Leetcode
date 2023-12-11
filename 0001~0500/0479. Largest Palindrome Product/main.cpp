/**
 * Source: is.gd/2FTdwQ
 * Date: 2023/12/9
 * Skill:
 * Ref:
 * Runtime: 62 ms, faster than 72.64% of C++ online submissions
 * Memory Usage: 6.59 MB, less than 81.13% of C++ online submissions
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
ll mod = 1337;


class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        ll lower_bound = pow(10, n - 1), upper_bound = pow(10, n) - 1;
        for (int i = upper_bound; i >= lower_bound; i--) {
            ll cur = i;
            for (ll j = cur; j > 0; j /= 10) {
                cur = cur * 10 + j % 10;
            }
            for (ll j = sqrt(cur); j <= upper_bound; j++) {
                if (cur / j < lower_bound) break;
                if (cur % j == 0 && cur / j <= upper_bound) {
                    return cur % mod;
                }
            }
        }
        return 9;
    }
};