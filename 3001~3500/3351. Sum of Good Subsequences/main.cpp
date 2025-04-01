/**
 * Source: t.ly/ZoXfM
 * Date: 2025/1/23
 * Skill:
 * Ref:
 * Runtime: 39 ms, faster than 92.00% of C++ online submissions
 * Memory Usage: 96.59 MB, less than 93.12% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
 *      0 <= nums[i] <= 10 ** 5
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
const int MOD = 1e9+7, MX = 1e5+1; 


class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        ll res = 0, cnt[MX] = {0}, total[MX] = {0};
        for (auto &i: nums) {
            ll num = i, time = 1;
            if (i - 1 >= 0) {
                time = (time + cnt[i-1]) % MOD;
                num = (cnt[i-1] * i + total[i-1] + num) % MOD;
            }
            if (i + 1 < MX) {
                time = (time + cnt[i+1]) % MOD;
                num = (cnt[i+1] * i + total[i+1] + num) % MOD;
            }
            res = (res + num) % MOD;
            cnt[i] = (cnt[i] + time) % MOD;
            total[i] = (total[i] + num) % MOD;
        }
        return res;
    }
};
