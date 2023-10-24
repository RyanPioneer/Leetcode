/**
 * Source: tinyurl.com/yqx84hco
 * Date: 2023/10/24
 * Skill:
 * Runtime: 3 ms, faster than 78.34% of C++ online submissions
 * Memory Usage: 8.49 MB, less than 27.19% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= costs.length <= 100
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
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(begin(costs), end(costs), [](vector<int> &a, vector<int> &b) {
            return abs(a[0] - a[1]) > abs(b[0] - b[1]);
        });
        int res = 0, first = 0, second = 0, n = costs.size() / 2;
        for (auto c: costs) {
            if (second == n || (first < n && c[0] < c[1])) {
                res += c[0];
                first++;
            } else {
                res += c[1];
                second++;
            }
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