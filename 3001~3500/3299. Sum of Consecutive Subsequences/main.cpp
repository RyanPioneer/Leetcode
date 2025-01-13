/**
 * Source: ibit.ly/g7tIm
 * Date: 2024/10/4
 * Skill:
 * Ref:
 * Runtime: 888 ms, faster than 10.77% of C++ online submissions
 * Memory Usage: 386.31 MB, less than 6.15% of C++ online submissions
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
    int getSum(vector<int>& nums) {
        auto get_sum = [&](int dir) {
            ll total = 0;
            unordered_map<int, ll> cnt, subsequence_sum;
            for (auto &i: nums) {
                cnt[i] = (cnt[i] + cnt[i+dir] + 1) % MOD;
                subsequence_sum[i] = (subsequence_sum[i] + subsequence_sum[i + dir] + i * (cnt[i + dir] + 1)) % MOD;
                total = (total + subsequence_sum[i + dir] + i * cnt[i + dir]) % MOD;
            }
            return total;
        };

        return (accumulate(begin(nums), end(nums), 0ll) % MOD + get_sum(1) + get_sum(-1)) % MOD;
    }
};