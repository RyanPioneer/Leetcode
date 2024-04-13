/**
 * Source: is.gd/r5LJOu
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 72 ms, faster than 92.81% of C++ online submissions
 * Memory Usage: 116.26 MB, less than 18.59% of C++ online submissions
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
    long long countAlternatingSubarrays(vector<int>& nums) {
        ll res = 0;
        int left = 0, n = nums.size();
        while (left < n) {
            int right = left;
            while (right + 1 < n && nums[right] != nums[right + 1]) right++;
            ll len = right - left + 1;
            res += len * (len + 1) / 2;
            left = right + 1;
        }
        return res;
    }
};