/**
 * Source: t.ly/TuXcb
 * Date: 2023/10/14
 * Skill:
 * Runtime: 213 ms, faster than 60.71% of C++ online submissions
 * Memory Usage: 86.31 MB, less than 36.91% of C++ online submissions
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
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (int i = 0; i < grid.size(); ++i)
            for (int j = 0; j < grid[0].size(); ++j)
                nums.push_back(grid[i][j]);
        sort(begin(nums), end(nums));
        int median = nums[nums.size() / 2 - (nums.size() % 2 == 0)], res = 0;
        for (auto i: nums) {
            int diff = abs(i - median);
            if (diff % x != 0)
                return -1;
            res += diff / x;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}