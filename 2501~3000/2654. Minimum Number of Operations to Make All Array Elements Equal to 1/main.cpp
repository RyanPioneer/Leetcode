/**
 * Source: twtr.to/6HMym
 * Date: 2023/10/18
 * Skill:
 * Runtime: 4 ms, faster than 71.60% of C++ online submissions
 * Memory Usage: 27.84 MB, less than 40.24% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= nums.length <= 50
 *      1 <= nums[i] <= 10 ** 6
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0, sz = nums.size(), res = INT32_MAX;
        for (auto i: nums)
            if (i == 1)
                cnt++;
        if (cnt > 0)
            return sz - cnt;
        for (int i = 0; i < sz; i++) {
            int num = nums[i];
            for (int j = i; j < sz; j++) {
                num = gcd(num, nums[j]);
                if (num == 1) {
                    res = min(res, j - i + 1);
                    break;
                }
            }
        }
        return res == INT32_MAX ? -1 : sz + res - 2;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}