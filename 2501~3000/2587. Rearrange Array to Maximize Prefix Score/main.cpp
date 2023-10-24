/**
 * Source: tinyurl.com/yq7t7vf8
 * Date: 2023/10/24
 * Skill:
 * Runtime: 160 ms, faster than 25.66% of C++ online submissions
 * Memory Usage: 83.6 MB, less than 35.2% of C++ online submissions
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
    int maxScore(vector<int>& nums) {
        sort(rbegin(nums), rend(nums));
        int res = 0;
        ll cur_sum = 0;
        for (auto i: nums) {
            cur_sum += i;
            if (cur_sum > 0)
                res++;
            else
                return res;
        }
        return res;
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