/**
 * Source: ibit.ly/7938A
 * Date: 2024/10/3
 * Skill:
 * Ref:
 * Runtime: 118 ms, faster than 44.83% of C++ online submissions
 * Memory Usage: 128.86 MB, less than 81.61% of C++ online submissions
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
        ll res = accumulate(begin(nums), end(nums), 0ll) % MOD;
        int sz = nums.size();
        for (ll left = 0; left < sz;) {
            if (left + 1 == sz || abs(nums[left] - nums[left + 1]) != 1) {
                left++;
            } else {
                ll right = left + 1, diff = nums[left + 1] - nums[left];
                while (right + 1 < sz && (nums[right + 1] - nums[right]) == diff) {
                    right++;
                }
                res = (res + calculate(nums, left, right)) % MOD;
                left = right;
            }
        }
        return res;
    }
    ll calculate(vector<int>& nums, ll l, ll r) {
        ll res = 0;
        for (ll i = l; i <= r; i++) {
            res = (res + ((i - l + 1) * (r - i + 1) - 1) % MOD * nums[i] % MOD) % MOD;
        }
        return res;
    }
};