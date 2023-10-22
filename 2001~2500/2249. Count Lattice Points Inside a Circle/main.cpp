/**
 * Source: tinyurl.com/ykmmt7z5
 * Date: 2023/10/22
 * Skill:
 * Runtime: 2282 ms, faster than 5.05% of C++ online submissions
 * Memory Usage: 562.76 MB, less than 5.30% of C++ online submissions
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
    int countLatticePoints(vector<vector<int>>& circles) {
        int res = 0, x_limit = 0, y_limit = 0, x_small = 200, y_small = 200;
        for (auto c: circles) {
            x_limit = max(x_limit, c[0] + c[2]);
            x_small = min(x_small, c[0] - c[2]);
            y_limit = max(y_limit, c[1] + c[2]);
            y_small = min(y_small, c[1] - c[2]);
        }
        for (int x = x_small; x <= x_limit; x++) {
            for (int y = y_small; y <= y_limit; y++) {
                for (auto c: circles) {
                    if ((x - c[0]) * (x - c[0]) + (y - c[1]) * (y - c[1]) <= c[2] * c[2]) {
                        res++;
                        break;
                    }
                }
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