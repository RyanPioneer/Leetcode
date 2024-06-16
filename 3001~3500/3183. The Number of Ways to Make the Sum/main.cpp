/**
 * Source: ibit.ly/15hQN
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 470 ms, faster than 11.58% of C++ online submissions
 * Memory Usage: 37.03 MB, less than 25.26% of C++ online submissions
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
typedef pair<int, int> PII;
const ll MOD = 1e9+7;
map<PII, ll> mp;


class Solution {
public:
    int numberOfWays(int n) {

        function<ll(PII)> helper = [&](PII i) {
            if (mp.find(i) != end(mp)) {
                return mp[i];
            }
            if (i.first < 0) return 0ll;
            if (i.first == 0) return 1ll;
            ll num = 0;
            if (i.second >= 6) {
                num = (num + helper(MK(i.first - 6, 6))) % MOD;
            }
            if (i.second >= 2) {
                num = (num + helper(MK(i.first - 2, 2))) % MOD;
            }
            if (i.second >= 1) {
                num = (num + helper(MK(i.first - 1, 1))) % MOD;
            }
            return mp[i] = num;
        };

        return (helper(MK(n, 6)) + helper(MK(n-4, 6)) + helper(MK(n-8, 6))) % MOD;
    }
};