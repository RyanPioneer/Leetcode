/**
 * Source: ibit.ly/M3pyN
 * Date: 2023/10/2
 * Skill:
 * Runtime: 3 ms, faster than 99.83% of C++ online submissions
 * Memory Usage: 8.75 MB, less than 40.14% of C++ online submissions
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
    int maximum = 0, res = 0;
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int sz = nums.size();
        for (auto i: nums)
            maximum |= i;
        dfs(0, 0, nums);
        return res;
    }
    void dfs(int idx, int cur_sum, vector<int>& nums) {
        if (cur_sum == maximum) {
            res += pow(2, nums.size() - idx);
            return;
        }
        if (idx == nums.size())
            return;
        dfs(idx + 1, cur_sum, nums);
        dfs(idx + 1, cur_sum | nums[idx], nums);
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}