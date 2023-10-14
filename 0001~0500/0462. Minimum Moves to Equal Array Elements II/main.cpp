/**
 * Source: ibit.ly/-dZNj
 * Date: 2023/10/14
 * Skill:
 * Runtime: 8 ms, faster than 71.74% of C++ online submissions
 * Memory Usage: 12.14 MB, less than 32.83% of C++ online submissions
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
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2 - (nums.size() % 2 == 0)], res = 0;
        for (auto i: nums)
            res += abs(i - median);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}