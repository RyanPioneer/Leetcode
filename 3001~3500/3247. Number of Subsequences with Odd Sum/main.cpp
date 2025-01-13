/**
 * Source: ibit.ly/js7TH
 * Date: 2024/8/14
 * Skill:
 * Ref:
 * Runtime: 124 ms, faster than 92.31% of C++ online submissions
 * Memory Usage: 109.86 MB, less than 81.54% of C++ online submissions
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
const ll MOD = 1e9+7;


class Solution {
public:
    int subsequenceCount(vector<int>& nums) {
        ll res = 0;
        ll odd = 0, even = 0, tmp;
        for (auto &i: nums) {
            tmp = odd;
            if (i % 2) {
                res = (res + even + 1) % MOD;
                odd = (odd + even + 1) % MOD;
                even = (even + tmp) % MOD;
            } else {
                res = (res + odd) % MOD;
                odd = odd * 2 % MOD;
                even = (even * 2 + 1) % MOD;
            }
        }
        return res;
    }
};