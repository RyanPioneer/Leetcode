/**
 * Source: jpeg.ly/cceDq
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 33.33% of C++ online submissions
 * Memory Usage: 18.73 MB, less than 8.33% of C++ online submissions
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


ll quick_pow(ll x, ll n, ll m) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % m;
        x = x * x % m;
    }
    return res;
}


class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < variables.size(); i++) {
            auto& v = variables[i];
            ll num = quick_pow(quick_pow(v[0], v[1], 10), v[2], v[3]);
            if (num == target) res.push_back(i);
        }
        return res;
    }
};