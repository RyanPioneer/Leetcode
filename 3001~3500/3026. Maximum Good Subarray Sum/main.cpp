/**
 * Source: jpeg.ly/yXZHn
 * Date: 2024/2/4
 * Skill:
 * Ref:
 * Runtime: 253ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 140.29 MB, less than 40.00% of C++ online submissions
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


ll presum[100001];

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, ll> num2presum;
        ll presum = 0, res = LLONG_MIN;
        for (auto &i: nums) {
            presum += i;
            if (num2presum.find(i + k) != end(num2presum)) {
                res = max(res, presum - num2presum[i + k] + i + k);
            }
            if (num2presum.find(i - k) != end(num2presum)) {
                res = max(res, presum - num2presum[i - k] + i - k);
            }
            if (num2presum.find(i) == end(num2presum)) {
                num2presum[i] = presum;
            } else {
                num2presum[i] = min(num2presum[i], presum);
            }
        }
        return res == LLONG_MIN ? 0 : res;
    }
};