/**
 * Source: https://rb.gy/0migv
 * Date: 2023/11/28
 * Skill:
 * Ref:
 * Runtime: 107 ms, faster than 96.57% of C++ online submissions
 * Memory Usage: 30.84 MB, less than 97.71% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
ll mod = 1e9+7;


class Solution {
public:
    int numberOfWays(string corridor) {
        int n = corridor.length(), pos = 0, num;
        ll res = 1;
        bool found = false;
        while (pos < n) {
            num = 0;
            while (pos < n && num < 2) {
                num += corridor[pos++] == 'S';
            }
            if (num == 2) found = true;
            ll p = 1;
            while (pos < n && corridor[pos] == 'P') {
                p++;
                pos++;
            }
            if (pos < n) res = res * p % mod;
        }
        return found && num != 1 ? res : 0;
    }
};