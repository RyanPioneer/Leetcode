/**
 * Source: tinyurl.com/24ypvnaa
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.63 MB, less than 100.00% of C++ online submissions
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


class Solution {
public:
    long long minEnd(int n, int x) {
        n--;
        ll res = x;
        int oneNum = 0, tmp = x;

        while (tmp > 0) {
            if ((tmp & 1)) {
                oneNum++;
            }
            tmp >>= 1;
        }

        ll fac = 1ll << (62 - oneNum);

        for (int i = 62; i >= 0; i--) {
            if ((1ll << i) & x) continue;
            if (fac <= n) {
                res |= 1ll << i;
                n -= fac;
            }
            fac >>= 1;
        }
        return res;
    }
};