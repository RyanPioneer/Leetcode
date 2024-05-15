/**
 * Source: ibit.ly/J2i83
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 294 ms, faster than 84.62% of C++ online submissions
 * Memory Usage: 144.55 MB, less than 100.00% of C++ online submissions
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
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {
        sort(begin(ranges), end(ranges), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        int right = 0;
        for (auto &i: ranges) {
            if (i[0] > right) {
                res.push_back({right, i[0] - 1});
            }
            right = max(right, i[1] + 1);
        }
        if (right < n) {
            res.push_back({right, n - 1});
        }
        return res;
    }
};