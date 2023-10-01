/**
 * Source: ibit.ly/_EL_R
 * Date: 2023/10/1
 * Skill:
 * Runtime: 121 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 86.52 MB, less than 100.00% of C++ online submissions
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


#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll res = (ll)(nums[0] - nums[1]) * nums[2];
        int cur_max = max(nums[0], nums[1]), diff_max = nums[0] - nums[1];
        for (int i = 3; i < nums.size(); i++) {
            diff_max = max(diff_max, cur_max - nums[i - 1]);
            cur_max = max(cur_max, nums[i - 1]);
            res = max(res, (ll)diff_max * nums[i]);
        }
        return res < 0 ? 0 : res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}