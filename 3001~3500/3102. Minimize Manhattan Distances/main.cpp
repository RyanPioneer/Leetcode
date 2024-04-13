/**
 * Source: is.gd/5MWbok
 * Date: 2024/4/7
 * Skill: 最長距離為左上到右下或是右上到左下
 * Ref:
 * Runtime: 230 ms, faster than 85.20% of C++ online submissions
 * Memory Usage: 120.70 MB, less than 98.14% of C++ online submissions
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
#define ll long long


class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int ru1 = 0, ru2 = 1, lu1 = 0, lu2 = 1, rd1 = 0, rd2 = 1, ld1 = 0, ld2 = 1;
        int n = points.size(), res = INT32_MAX;
        for (int i = 1; i < n; i++) {
            if (points[i][0] + points[i][1] > points[ru1][0] + points[ru1][1]) {
                ru2 = ru1, ru1 = i;
            } else if (points[i][0] + points[i][1] > points[ru2][0] + points[ru2][1]) {
                ru2 = i;
            }
            if (points[i][1] - points[i][0] > points[lu1][1] - points[lu1][0]) {
                lu2 = lu1, lu1 = i;
            } else if (points[i][1] - points[i][0] > points[lu2][1] - points[lu2][0]) {
                lu2 = i;
            }
            if (points[i][0] - points[i][1] > points[rd1][0] - points[rd1][1]) {
                rd2 = rd1, rd1 = i;
            } else if (points[i][0] - points[i][1] > points[rd2][0] - points[rd2][1]) {
                rd2 = i;
            }
            if (-points[i][0] - points[i][1] > -points[ld1][0] - points[ld1][1]) {
                ld2 = ld1, ld1 = i;
            } else if (-points[i][0] - points[i][1] > -points[ld2][0] - points[ld2][1]) {
                ld2 = i;
            }
        }
        for (int i = 0; i < n; i++) {
            int cur_max = 0;
            if (i != ru1 && i != ld1) {
                cur_max = max(cur_max, abs(points[ru1][0] - points[ld1][0]) + abs(points[ru1][1] - points[ld1][1]));
            }else if (i == ru1) {
                cur_max = max(cur_max, abs(points[ru2][0] - points[ld1][0]) + abs(points[ru2][1] - points[ld1][1]));
            } else {
                cur_max = max(cur_max, abs(points[ru1][0] - points[ld2][0]) + abs(points[ru1][1] - points[ld2][1]));
            }
            if (i != rd1 && i != lu1) {
                cur_max = max(cur_max, abs(points[rd1][0] - points[lu1][0]) + abs(points[lu1][1] - points[rd1][1]));
            }else if (i == rd1) {
                cur_max = max(cur_max, abs(points[rd2][0] - points[lu1][0]) + abs(points[lu1][1] - points[rd2][1]));
            } else {
                cur_max = max(cur_max, abs(points[rd1][0] - points[lu2][0]) + abs(points[lu2][1] - points[rd1][1]));
            }
            res = min(res, cur_max);
        }
        return res;
    }
};