/**
 * Source: t.ly/Iyl-k
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 39.92 MB, less than 66.12% of C++ online submissions
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

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        if (accumulate(nums.begin(), nums.end(), 0) == nums.size()) {
            return nums.size();
        }
        int res = 0, prev = 0, cur = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur++;
            } else {
                res = max(res, cur + prev + 1);
                prev = cur;
                cur = 0;
            }
        }
        res = max(res, cur + prev + 1);
        return res;
    }
};
