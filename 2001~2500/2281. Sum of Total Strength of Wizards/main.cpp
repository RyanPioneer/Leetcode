/**
 * Source: tinyurl.com/2bvutfmw
 * Date: 2023/10/19
 * Skill:
 * Runtime: 223 ms, faster than 23.26% of C++ online submissions
 * Memory Usage: 111.26 MB, less than 18.27% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int totalStrength(vector<int>& strength) {
        ll res = 0, mod = 1e9+7;
        int sz = strength.size();
        vector<int> smaller_before(sz, -1), smaller_after(sz, sz);
        stack<int> before, after;
        for (int i = 0; i < sz; ++i) {
            while (!before.empty() && strength[i] <= strength[before.top()])
                before.pop();
            if (!before.empty())
                smaller_before[i] = before.top();
            before.push(i);
            int j = sz - 1 - i;
            while (!after.empty() && strength[j] < strength[after.top()])
                after.pop();
            if (!after.empty())
                smaller_after[j] = after.top();
            after.push(j);
        }
        vector<ll> presum(sz + 1, 0), left_sum(sz + 1, 0), right_sum(sz + 1, 0);
        ll right = 0;
        for (int i = 0; i < sz; i++) {
            presum[i + 1] = presum[i] + strength[i];
            left_sum[i + 1] = left_sum[i] + presum[i + 1];
            int j = sz - 1 - i;
            right += strength[j];
            right_sum[j] = right_sum[j + 1] + right;
        }
        for (int i = 0; i < sz; i++) {
            ll num = strength[i];
            ll left = smaller_before[i];
            right = smaller_after[i];
            ll left_cnt = i - left - 1, right_cnt = right - i - 1;
            ll left_num = (right_sum[left + 1] - right_sum[i] - left_cnt * (presum[sz] - presum[i])) % mod;
            ll right_num = (left_sum[right] - left_sum[i + 1] - right_cnt * presum[i + 1]) % mod;
            res = (res + num * num % mod * (left_cnt + 1) * (right_cnt + 1) % mod) % mod;
            res = (res + num * left_num % mod * (right_cnt + 1) % mod) % mod;
            res = (res + num * right_num % mod * (left_cnt + 1) % mod) % mod;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    ll res = s.totalStrength(nums);
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}