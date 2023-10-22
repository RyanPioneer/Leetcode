/**
 * Source: tinyurl.com/yua2lrzf
 * Date: 2023/10/22
 * Skill:
 * Runtime: 90 ms, faster than 59.88% of C++ online submissions
 * Memory Usage: 63.81 MB, less than 30.72% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= circles.length <= 200
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
    int maximumTop(vector<int>& nums, int k) {
        int sz = nums.size(), num = 0;
        if (sz == 1 && k % 2 == 1)
            return -1;
        if (k > sz)
            return *max_element(begin(nums), end(nums));
        else if (k < sz)
            num = nums[k];
        for (int i = 0; i < k - 1; i++)
            num = max(num, nums[i]);
        return num;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}