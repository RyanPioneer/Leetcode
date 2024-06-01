/**
 * Source: t.ly/xNzfS
 * Date: 2024/5/30
 * Skill:
 * Ref:
 * Runtime: 32 ms, faster than 96.82% of C++ online submissions
 * Memory Usage: 54.60 MB, less than 76.82% of C++ online submissions
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


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, n = nums.size(), l = -1, r = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > right) {
                l = i;
                r = -1;
            } else {
                if (left <= nums[i] && nums[i] <= right) {
                    r = i;
                }
                if (r != -1) {
                    res += r - l;
                }
            }
        }

        return res;
    }
};