/**
 * Source: t.ly/CVrJI
 * Date: 2023/10/14
 * Skill:
 * Runtime: 306 ms, faster than 5.40% of C++ online submissions
 * Memory Usage: 101.22 MB, less than 6.05% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<vector<ll>> q;
        vector<ll> res(queries.size());
        for (int i = 0; i < queries.size(); ++i)
            q.push_back({queries[i], i});
        sort(begin(q), end(q));
        sort(begin(nums), end(nums));
        ll cur_sum = accumulate(begin(nums), end(nums), 0ll), prev_sum = 0;
        int idx = 0, sz = nums.size();
        for (int i = 0; i < q.size(); i++) {
            while (idx < sz && nums[idx] <= q[i][0]) {
                prev_sum += nums[idx];
                cur_sum -= nums[idx++];
            }
            res[q[i][1]] = q[i][0] * idx - prev_sum + cur_sum - q[i][0] * (sz - idx);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}