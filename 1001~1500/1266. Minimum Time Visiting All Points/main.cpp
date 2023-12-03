/**
 * Source: jpeg.ly/-eXkH
 * Date: 2023/12/3
 * Skill:
 * Ref:
 * Runtime: 5 ms, faster than 76.79% of C++ online submissions
 * Memory Usage: 10.49 MB, less than 64.64% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i + 1 < SZ(points); i++) {
            int h = abs(points[i][0] - points[i + 1][0]);
            int v = abs(points[i][1] - points[i + 1][1]);
            res += max(h, v);
        }
        return res;
    }
};