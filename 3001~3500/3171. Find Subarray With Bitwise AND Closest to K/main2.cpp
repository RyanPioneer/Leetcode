/**
 * Source: t.ly/juBki
 * Date: 2024/6/3
 * Skill:
 * Ref:
 * Runtime: 115 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 94.62 MB, less than 50.00% of C++ online submissions
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
    int minimumDifference(vector<int>& nums, int k) {
        int res = INT32_MAX;
        for (int i = 0; i < nums.size(); i++) {
            res = min(res, abs(nums[i] - k));
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] == (nums[j] & nums[i])) {
                    break;
                }
                nums[j] &= nums[i];
                res = min(res, abs(nums[j] - k));
            }
        }
        return res;
    }
};