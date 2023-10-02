/**
 * Source: ibit.ly/EMVN7
 * Date: 2023/10/2
 * Skill:
 * Runtime: 195 ms, faster than 85.83% of C++ online submissions
 * Memory Usage: 116.52 MB, less than 86.07% of C++ online submissions
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
    vector<int> findLonely(vector<int>& nums) {
        vector<int> res;
        int sz = nums.size();
        if (sz == 1)
            return nums;
        if (sz == 2) {
            if (abs(nums[0] - nums[1]) > 1)
                return nums;
            else
                return res;
        }
        sort(nums.begin(), nums.end());
        if (nums[sz - 1] - nums[sz - 2] > 1)
            res.push_back(nums[sz - 1]);
        if (nums[1] - nums[0] > 1)
            res.push_back(nums[0]);
        for (int i = 1; i < sz - 1; i++)
            if (nums[i + 1] - nums[i] > 1 && nums[i] - nums[i - 1] > 1)
                res.push_back(nums[i]);
        return res;
    }
};



int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}