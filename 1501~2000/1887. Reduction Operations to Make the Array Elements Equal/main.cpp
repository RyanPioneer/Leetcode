/**
 * Source: twtr.to/Zyzq-
 * Date: 2023/11/19
 * Skill:
 * Runtime: 157 ms, faster than 71.47% of C++ online submissions
 * Memory Usage: 83.09 MB, less than 88.96% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(begin(nums), end(nums), greater<int>());
        int res = 0, idx = 0, len = nums.size();
        while (idx + 1 < len) {
            while (idx + 1 < len && nums[idx] == nums[idx + 1]) idx++;
            if (idx == len - 1) break;
            res += idx + 1;
            idx++;
        }
        return res;
    }
};