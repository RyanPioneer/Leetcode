/**
 * Source: ibit.ly/zsjzT
 * Date: 2023/10/9
 * Skill:
 * Runtime: 6 ms, faster than 53.78% of C++ online submissions
 * Memory Usage: 13.98 MB, less than 25.30% of C++ online submissions
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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res {-1, -1};
        auto pos = lower_bound(nums.begin(), nums.end(), target);
        if (pos != end(nums) && *pos == target) {
            res[0] = res[1] = pos - begin(nums);
            pos = upper_bound(nums.begin(), nums.end(), target);
            if (pos != begin(nums) && *prev(pos) == target)
                res[1] = pos - begin(nums) - 1;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}