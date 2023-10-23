/**
 * Source: tinyurl.com/yr7sa7ko
 * Date: 2023/10/23
 * Skill:
 * Runtime: 172 ms, faster than 51.78% of C++ online submissions
 * Memory Usage: 99.57 MB, less than 40.00% of C++ online submissions
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
        stack<int> before;
        for (int i = 0; i < sz; i++) {
            while (!before.empty() && nums[i] < nums[before.top()]) {
                smaller_after[before.top()] = i;
                before.pop();
            }
            if (!before.empty())
                smaller_before[i] = before.top();
            before.push(i);
        }
        for (int i = 0; i < sz; i++) {
            if (smaller_before[i] < k && smaller_after[i] > k)
                res = max(res, nums[i] * (smaller_after[i] - smaller_before[i] - 1));
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