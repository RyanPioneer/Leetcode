/**
 * Source: is.gd/geE5Xz
 * Date: 2024/4/15
 * Skill:
 * Ref:
 * Runtime: 212 ms, faster than 42.86% of C++ online submissions
 * Memory Usage: 108.83 MB, less than 28.57% of C++ online submissions
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

const int MOD = 1e9+7, MX = 55;


class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        ll res = 0;
        int n = nums.size();

        sort(begin(nums), end(nums));

        function<void(int, int)> helper = [&](int left, int right) {
            int d = nums[right] - nums[left];

        };
    }
};