/**
 * Source: jpeg.ly/XxKJM
 * Date: 2024/2/4
 * Skill:
 * Ref:
 * Runtime: 23 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 32.20 MB, less than 12.50% of C++ online submissions
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
    int numberOfPairs(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        sort(begin(points), end(points), [](const vector<int>& a, const vector<int> &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for (int i = 0, prev_hi = INT32_MIN; i < n; i++, prev_hi = INT32_MIN) {
            for (int j = i + 1; j < n; j++) {
                if (points[i][1] < points[j][1] || prev_hi >= points[j][1]) continue;
                prev_hi = points[j][1];
                res++;
            }
        }
        return res;
    }
};