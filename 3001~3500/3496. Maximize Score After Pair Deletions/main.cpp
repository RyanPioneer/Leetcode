/**
 * Source: t.ly/ogwv5
 * Date: 2025/3/31
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 198.08 MB, less than 58.18% of C++ online submissions
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
    int maxScore(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0ll), sz = nums.size();
        int mi = (sz % 2) ? *min_element(nums.begin(), nums.end()) : INT32_MAX/2;
        for (int i = 0; i < sz; i++) {
            if (!(sz % 2) && i + 1 < sz) {
                mi = min(mi, nums[i] + nums[i + 1]);
            }
        }
        return total - mi;
    }
};
