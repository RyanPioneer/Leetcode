/**
 * Source: t.ly/g6ka5
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 109 ms, faster than 40.00% of C++ online submissions
 * Memory Usage: 30.99 MB, less than 40.00% of C++ online submissions
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
#define MK make_pair
#define SZ(X) ((int)(X).size())
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    int waysToReachStair(int k) {
        map<ti3, int> mp;
        int res = 0;

        function<int(ti3)> dfs = [&](ti3 t) {
            if (mp.find(t) != end(mp)) return mp[t];
            auto& [prev, add, num] = t;
            int r = num == k ? 1 : 0;
            if (num <= k) {
                r += dfs({add, add*2, num + add});
            }
            if (num > 0 && prev != -1) {
                r += dfs({-1, add, num-1});
            }
            return mp[t] = r;
        };

        return res + dfs({0, 1, 1});
    }
};