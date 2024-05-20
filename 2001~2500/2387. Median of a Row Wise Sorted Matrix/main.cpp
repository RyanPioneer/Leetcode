/**
 * Source: t.ly/u8GEN
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 111 ms, faster than 71.11% of C++ online submissions
 * Memory Usage: 37.59 MB, less than 86.67% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
    int matrixMedian(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int num = m * n / 2 + 1;
        int left = 0, right = 1e6;

        while (left < right) {
            int mid = (left + right) / 2;
            int t = 0;
            for (auto &r: grid) {
                auto pos = upper_bound(begin(r), end(r), mid);
                t += pos - begin(r);
            }
            if (t >= num) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};