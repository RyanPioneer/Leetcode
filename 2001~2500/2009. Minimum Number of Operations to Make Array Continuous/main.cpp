/**
 * Source: ibit.ly/UbwFK
 * Date: 2023/10/10
 * Skill:
 * Runtime: 151 ms, faster than 73.01% of C++ online submissions
 * Memory Usage: 64.80 MB, less than 67.15% of C++ online submissions
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
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 1, sz = nums.size(), left = 0, num = 1;
        for (int i = 1; i < sz; ++i) {
            if (nums[i] != nums[i - 1])
                num++;
            while (nums[i] - nums[left] >= sz) {
                if (nums[left] != nums[left + 1])
                    num--;
                left++;
            }
            res = max(res, num);
        }
        return sz - res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}