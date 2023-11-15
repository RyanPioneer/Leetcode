/**
 * Source: ibit.ly/PH-4e
 * Date: 2023/11/15
 * Skill:
 * Runtime: 408 ms, faster than 55.48% of C++ online submissions
 * Memory Usage: 189.20 MB, less than 57.53% of C++ online submissions
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


typedef pair<int, int> pairs;

#define ll long long


ll mod = 1e9+7;
ll inv(ll x) {
    ll s = 1;
    for (; x > 1; x = mod % x) s = s * (mod - mod / x) % mod;
    return s;
}


class Fancy {
    int idx = 0;
    vector<int> nums;
    vector<ll> add, mul;
    ll cur_sum = 0, cur_mul = 1;
public:
    Fancy() {
    }

    void append(int val) {
        idx++;
        nums.push_back(val);
        add.push_back(cur_sum);
        mul.push_back(cur_mul);
    }

    void addAll(int inc) {
        cur_sum = (cur_sum + inc) % mod;
    }

    void multAll(int m) {
        cur_mul = cur_mul * m % mod;
        cur_sum = (cur_sum * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= this->idx) return -1;
        ll res = (cur_sum % mod - ((add[idx] - nums[idx]) * cur_mul % mod) * inv(mul[idx]) % mod + mod) % mod;
        return res;
    }
};



int main() {
}