/**
 * Source: t.ly/p6GRJ
 * Date: 2025/4/15
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 35.40 MB, less than 69.14% of C++ online submissions
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
    int missingElement(vector<int>& nums, int k) {
        int sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            int diff = nums[i + 1] - nums[i] - 1;
            if (diff >= k) {
                return nums[i] + k;
            }
            k -= diff;
        }
        return nums[sz - 1] + k;
    }
};
