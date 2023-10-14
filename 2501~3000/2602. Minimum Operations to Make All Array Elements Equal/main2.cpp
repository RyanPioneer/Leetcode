/**
 * Source: t.ly/CVrJI
 * Date: 2023/10/14
 * Skill:
 * Runtime: 178 ms, faster than 82.07% of C++ online submissions
 * Memory Usage: 84.86 MB, less than 9.07% of C++ online submissions
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
        vector<ll> res, presum;
        sort(begin(nums), end(nums));
        presum.push_back(0);
        for (auto i: nums)
            presum.push_back(presum.back() + i);
        ll total = accumulate(begin(nums), end(nums), 0ll), sz = nums.size();
        for (auto q: queries) {
            auto pos = upper_bound(begin(nums), end(nums), q);
            if (pos == begin(nums))
                res.push_back(total - q * sz);
            else if (pos == end(nums))
                res.push_back(q * sz - total);
            else {
                int idx = pos - begin(nums);
                res.push_back((ll)q * idx - presum[idx] + (total - presum[idx]) - q * (sz - idx));
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}