/**
 * Source: ibit.ly/5FWNf
 * Date: 2023/11/17
 * Skill:
 * Runtime: 176 ms, faster than 87.58% of C++ online submissions
 * Memory Usage: 96.51 MB, less than 61.58% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int res = INT32_MIN, n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            res = max(res, nums[i] + nums[n - 1 - i]);
        }
        return res;
    }
};


int main() {
    Solution s;
}