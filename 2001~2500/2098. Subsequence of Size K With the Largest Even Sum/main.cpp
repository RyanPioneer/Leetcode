/**
 * Source: ibit.ly/jTQgf
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 70 ms, faster than 84.00% of C++ online submissions
 * Memory Usage: 62.40 MB, less than 76.00% of C++ online submissions
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
const int MX = 1e3+10;


class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int odd = -1, even = -1, n = nums.size();
        ll res = 0;
        for (int i = n - 1; i >= n - k; i--) {
            res += nums[i];
            if (nums[i] % 2) {
                odd = nums[i];
            }
            if (nums[i] % 2 == 0) {
                even = nums[i];
            }
        }
        if (res % 2 == 0) return res;
        int odd1 = -1, even1 = -1;
        for (int i = 0; i < n - k; i++) {
            if (nums[i] % 2) {
                odd1 = nums[i];
            }
            if (nums[i] % 2 == 0) {
                even1 = nums[i];
            }
        }
        ll ans = -1;
        if (odd1 != -1 && even != -1) {
            ans = max(ans, res + odd1 - even);
        }
        if (even1 != -1 && odd != -1) {
            ans = max(ans, res + even1 - odd);
        }
        return ans;
    }
};