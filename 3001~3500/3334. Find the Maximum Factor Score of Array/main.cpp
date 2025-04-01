/**
 * Source: t.ly/BHrnn
 * Date: 2025/1/23
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 39.94% of C++ online submissions
 * Memory Usage: 26.21 MB, less than 54.31% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= nums.length <= 100
 *      1 <= nums[i] <= 30
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
#include <numeric> // std::gcd, std::lcm


using namespace std;
#define ll long long
const int MOD = 1e9+7, MX = 1e5+1; 


class Solution {
public:
    long long maxScore(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums.back() * nums.back();
        ll lcmNum = nums[0], gcdNum = nums[0];

        for (int i = 1; i < n; i++) {
            lcmNum = std::lcm(lcmNum, nums[i]);
            gcdNum = std::gcd(gcdNum, nums[i]);
        }

        ll res = lcmNum * gcdNum;

        for (int i = 0; i < n; i++) {
            lcmNum = (i == 0 ? nums[1] : nums[0]);
            gcdNum = (i == 0 ? nums[1] : nums[0]);
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                lcmNum = std::lcm(lcmNum, nums[j]);
                gcdNum = std::gcd(gcdNum, nums[j]);
            }
            res = max(res, lcmNum * gcdNum);
        }
        return res;
    }
};
