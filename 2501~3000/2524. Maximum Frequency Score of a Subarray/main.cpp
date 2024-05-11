/**
 * Source: t.ly/jcIYV
 * Date: 2024/5/7
 * Skill:
 * Ref:
 * Runtime: 224 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 78.24 MB, less than 16.67% of C++ online submissions
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
const int MOD = 1e9+7;


ll inv(int x) {
    ll s = 1;
    for (; x > 1; x = MOD % x) s = s * (MOD - MOD / x) % MOD;
    return s;
}


class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, int k) {
        ll score = 0, res = 0;
        unordered_map<ll, ll> mp, cnt;
        for (int i = 0; i < k; i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] == 1) {
                mp[nums[i]] = nums[i];
            } else {
                mp[nums[i]] = (mp[nums[i]] * nums[i]) % MOD;
            }
        }
        for (auto i: mp) {
            score = (score + i.second) % MOD;
        }
        res = score;
        for (int i = k; i < nums.size(); i++) {
            cnt[nums[i]]++;
            if (cnt[nums[i]] == 1) {
                mp[nums[i]] = nums[i];
            } else {
                mp[nums[i]] = (mp[nums[i]] * nums[i]) % MOD;
            }
            score = (score + mp[nums[i]] - (mp[nums[i]] * inv(nums[i]) % MOD)) % MOD;
            if (cnt[nums[i]] == 1) score++;
            cnt[nums[i - k]]--;
            if (cnt[nums[i - k]] == 0) {
                score = (score - nums[i - k]) % MOD;
                nums[i - k] = 1;
            } else {
                score = (score + (mp[nums[i - k]] * inv(nums[i - k])) - mp[nums[i - k]]) % MOD;
                mp[nums[i - k]] = (mp[nums[i - k]] * inv(nums[i - k])) % MOD;
            }
            res = max(res, score % MOD);
        }
        return res;
    }
};