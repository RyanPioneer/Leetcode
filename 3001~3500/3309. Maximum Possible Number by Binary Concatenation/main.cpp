/**
 * Source: is.gd/tBaGWk
 * Date: 2025/1/22
 * Skill:
 * Ref: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 25.45 MB, less than 70.26% of C++ online submissions
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
    int maxGoodNumber(vector<int>& nums) {
        int res = 0;

        auto getMul = [&](int num) {
            int mul = 1;
            while (num) {
                mul <<= 1;
                num >>= 1;
            }
            return mul;
        };
        
        function<void(int, int)> helper = [&](int idx, int num) {
            if (idx == nums.size()) {
                res = max(res, num);
                return;
            }
            for (int i = idx; i < nums.size(); i++) {
                swap(nums[i], nums[idx]);
                int t = num + getMul(num) * nums[idx];
                helper(idx + 1, t);
                swap(nums[i], nums[idx]);
            }
        };

        helper(0, 0);
        return res;
    }
};
