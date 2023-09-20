/**
 * Source: t.ly/GOihx
 * Date: 2023/9/20
 * Skill:
 * Runtime: 102 ms, faster than 98.51% of C++ online submissions
 * Memory Usage: 98.94 MB, less than 35.28% of C++ online submissions
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
    int minOperations(vector<int>& nums, int x) {
        int res = INT32_MAX, sz = nums.size(), cur_sum = 0;
        int target = accumulate(begin(nums), end(nums), -x);
        if (target == 0)
            return sz;
        if (target < 0)
            return -1;
        int left = 0, right = 0;
        while (right < sz) {
            while (right < sz && cur_sum < target)
                cur_sum += nums[right++];
            while (cur_sum > target)
                cur_sum -= nums[left++];
            if (cur_sum == target) {
                res = min(res, sz - (right - left));
                cur_sum -= nums[left++];
            }
        }
        return res == INT32_MAX ? -1 : res;
    }
};

int main() {

}