/**
 * Source: tinyurl.com/yq7t7vf8
 * Date: 2023/10/24
 * Skill:
 * Runtime: 115 ms, faster than 88.95% of C++ online submissions
 * Memory Usage: 83.33 MB, less than 65.54% of C++ online submissions
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
        auto p = partition(begin(nums), end(nums), [](int num) {
           return num > 0;
        });
        sort(p, end(nums), greater<int>());
        auto s = accumulate(begin(nums), p, 0ll);
        for (; p != end(nums); p++) {
            s += *p;
            if (s <= 0)
                break;
        }
        return p - begin(nums);
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