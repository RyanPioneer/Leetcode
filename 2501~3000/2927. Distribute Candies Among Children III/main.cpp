/**
 * Source: is.gd/1Nz6sH
 * Date: 2024/5/20
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.68 MB, less than 100.00% of C++ online submissions
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
    long long distributeCandies(int n, int limit) {
        auto comb2 = [](ll num) {
            if (num <= 1) return 0ll;
            return num * (num-1) / 2;
        };

        ll a = comb2(n+2);
        ll b = comb2(n-(limit+1)+2);
        ll c = comb2(n-2*(limit+1)+2);
        ll d = comb2(n-3*(limit+1)+2);
        return a - 3 * b + 3 * c - d;
    }
};