/**
 * Source: tinyurl.com/yr7sa7ko
 * Date: 2023/10/22
 * Skill:
 * Runtime: 117 ms, faster than 93.64% of C++ online submissions
 * Memory Usage: 89.68 MB, less than 80.92% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int sz = nums.size(), res = 0, l = k, r = k, min_val = nums[k];
        while (l >= 0 || r < sz) {
            while (l >= 0 && nums[l] >= min_val)
                l--;
            while (r < sz && nums[r] >= min_val)
                r++;
            res = max(res, min_val * (r - l - 1));
            min_val = max(l >= 0 ? nums[l] : INT32_MIN, r < sz ? nums[r] : INT32_MIN);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{89135};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}