/**
 * Source: tinyurl.com/yr7sa7ko
 * Date: 2023/10/22
 * Skill:
 * Runtime: 202 ms, faster than 41.67% of C++ online submissions
 * Memory Usage: 101.00 MB, less than 25.44% of C++ online submissions
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
        int sz = nums.size(), res = 0;
        vector<int> smaller_after(sz, sz), smaller_before(sz, -1);
        stack<int> before, after;
        for (int i = 0; i < sz; i++) {
            while (!before.empty() && nums[i] <= nums[before.top()])
                before.pop();
            if (!before.empty())
                smaller_before[i] = before.top();
            before.push(i);
            int j = sz - 1 - i;
            while (!after.empty() && nums[j] <= nums[after.top()])
                after.pop();
            if (!after.empty())
                smaller_after[j] = after.top();
            after.push(j);
        }
        for (int i = 0; i < sz; i++)
            if (smaller_before[i] < k && k < smaller_after[i])
                res = max(res, nums[i] * (smaller_after[i] - smaller_before[i] - 1));
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