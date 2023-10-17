/**
 * Source: twtr.to/KRvcO
 * Date: 2023/10/16
 * Skill:
 * Runtime: 201 ms, faster than 62.96% of C++ online submissions
 * Memory Usage: 67.17 MB, less than 95.06% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        ll lo = 0, hi = accumulate(begin(stations), end(stations), 0ll) + k;
        int n = stations.size();
        vector<int> nums;
        function<bool(ll num)> binary_search;
        binary_search = [&](ll num) {
            nums = stations;
            ll cur_sum = 0, budget = k;
            for (int i = 0; i <= r; i++)
                cur_sum += nums[i];
            if (cur_sum < num) {
                nums[r] += num - cur_sum;
                budget -= num - cur_sum;
                cur_sum = num;
            }
            int idx = 1;
            while (idx < n - r && budget >= 0) {
                cur_sum += nums[idx + r] - (idx - r - 1 >= 0 ? nums[idx - r - 1] : 0);
                if (cur_sum < num) {
                    nums[idx + r] += num - cur_sum;
                    budget -= num - cur_sum;
                    cur_sum = num;
                }
                idx++;
            }
            while (idx < n && budget >= 0) {
                cur_sum -= idx - r - 1 >= 0 ? nums[idx - r - 1] : 0;
                if (cur_sum < num) {
                    budget -= num - cur_sum;
                    cur_sum = num;
                }
                idx++;
            }
            return budget >= 0;
        };

        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if (binary_search(mid))
                lo = mid;
            else
                hi = mid - 1;
        }
        return hi;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}