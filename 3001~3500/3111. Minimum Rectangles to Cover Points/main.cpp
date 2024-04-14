/**
 * Source: is.gd/hs6YzV
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 240 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 118.20 MB, less than 60.00% of C++ online submissions
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
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        int res = 0, n = points.size();
        sort(begin(points), end(points), [&](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int left = 0;
        while (left < n) {
            res++;
            int right = left + 1;
            while (right < n && points[right][0] - points[left][0] <= w) right++;
            left = right;
        }
        return res;
    }
};