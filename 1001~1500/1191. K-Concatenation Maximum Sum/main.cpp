/**
 * Source: twtr.to/mqTah
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 37 ms, faster than 96.99% of C++ online submissions
 * Memory Usage: 39.74 MB, less than 94.28% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
ll mod = 1e9+7;


class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        ll left_max = 0, right_max = 0, mid_max = 0, total = accumulate(begin(arr), end(arr), 0ll);
        ll cur_presum = 0, min_presum = 0;
        for (auto &i: arr) {
            cur_presum += i;
            left_max = max(left_max, cur_presum);
            mid_max = max(mid_max, cur_presum - min_presum);
            min_presum = min(min_presum, cur_presum);
        }
        ll cur_post_sum = 0, res = 0;
        for (int i = SZ(arr) - 1; i >= 0; i--) {
            cur_post_sum += arr[i];
            right_max = max(right_max, cur_post_sum);
        }
        if (k > 1) res = max(res, left_max + right_max + max(total * (k - 2), 0ll));
        return max(res, mid_max) % mod;
    }
};