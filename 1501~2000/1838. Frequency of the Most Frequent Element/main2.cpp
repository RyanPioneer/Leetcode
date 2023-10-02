/**
 * Source: ibit.ly/SZiL8
 * Date: 2023/10/2
 * Skill:
 * Runtime: 168 ms, faster than 55.80% of C++ online submissions
 * Memory Usage: 99.27 MB, less than 24.32% of C++ online submissions
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
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int res = 1, left = 0;
        ll cur_sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            cur_sum += (ll)(nums[i] - nums[i - 1]) * (i - left);
            while (cur_sum > k)
                cur_sum -= nums[i] - nums[left++];
            res = max(res, i - left + 1);
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}