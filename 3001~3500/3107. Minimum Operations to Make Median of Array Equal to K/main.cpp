/**
 * Source: is.gd/K2CLAh
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 136 ms, faster than 81.75% of C++ online submissions
 * Memory Usage: 89.19 MB, less than 34.42% of C++ online submissions
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


class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ll res = 0;
        int n = nums.size();
        int pos = n / 2;

        sort(begin(nums), end(nums));
        for (int i = 0; i < n; i++) {
            if (i < pos && nums[i] > k) {
                res += nums[i] - k;
            } else if (i == pos && nums[i] != k) {
                res += abs(nums[i] - k);
            } else if (i > pos && nums[i] < k) {
                res += k - nums[i];
            }
        }
        return res;
    }
};