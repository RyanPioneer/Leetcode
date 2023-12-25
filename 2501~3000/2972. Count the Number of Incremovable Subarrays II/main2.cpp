/**
 * Source: is.gd/bWyu9N
 * Date: 2023/12/25
 * Skill:
 * Ref:
 * Runtime: 120 ms, faster than 62.50% of C++ online submissions
 * Memory Usage: 94.71 MB, less than 12.50% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int len = SZ(nums), left = 1;
        while (left < len && nums[left] > nums[left - 1]) left++;
        if (left == len) return (ll)len * (len + 1) / 2;
        ll res = left + 1;
        for (int right = len - 1; right >= 0; right--) {
            while (left > 0 && nums[right] <= nums[left - 1]) left--;
            res += left + 1;
            if (nums[right - 1] >= nums[right]) break;
        }
        return res;
    }
};
