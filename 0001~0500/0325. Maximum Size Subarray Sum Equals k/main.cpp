/**
 * Source: t.ly/y3cAJ
 * Date: 2025/4/10
 * Skill:
 * Ref:
 * Runtime: 148 ms, faster than 94.58% of C++ online submissions
 * Memory Usage: 130.86 MB, less than 62.65% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

#define ll long long

class Solution {
   public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        ll curSum = 0;
        unordered_map<ll, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];
            if (curSum == k) {
                res = i + 1;
            }
            if (mp.find(curSum - k) != mp.end()) {
                res = max(res, i - mp[curSum - k]);
            }
            if (mp.find(curSum) == mp.end()) {
                mp[curSum] = i;
            }
        }
        return res;
    }
};
