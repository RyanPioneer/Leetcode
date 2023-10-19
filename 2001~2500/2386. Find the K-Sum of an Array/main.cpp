/**
 * Source: tinyurl.com/yu7nhqjy
 * Date: 2023/10/18
 * Skill:
 * Runtime: 170 ms, faster than 39.39% of C++ online submissions
 * Memory Usage: 64.48 MB, less than 70.45% of C++ online submissions
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
typedef pair<ll, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        ll total = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            if (nums[i] >= 0)
                total += nums[i];
            else
                nums[i] *= -1;
        }
        if (k == 1)
            return total;
        sort(begin(nums), end(nums));
        priority_queue<pairs, vector<pairs>, greater<>> pq;
        pq.push({nums[0], 0});
        for (int i = 0; i < k - 1; i++) {
            auto [cur_sum, idx] = pq.top();
            pq.pop();
            if (i == k - 2)
                return total - cur_sum;
            if (idx + 1 < sz) {
                pq.push({cur_sum + nums[idx + 1], idx + 1});
                pq.push({cur_sum + nums[idx + 1] - nums[idx], idx + 1});
            }
        }
        return -1;
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