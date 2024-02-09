/**
 * Source: is.gd/hOAuk1
 * Date: 2024/2/9
 * Skill:
 * Ref:
 * Runtime: 417 ms, faster than 65.65% of C++ online submissions
 * Memory Usage: 115.86 MB, less than 95.50% of C++ online submissions
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
typedef unsigned long long ULL;

const int MX = 501;


class Solution {
    int num[MX][MX][2] = {0};
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int m = image.size(), n = image[0].size(), dir[5] = {0, 1, 0, -1, 0};
        vector<vector<int>> res = image;

        for (int i = 2; i < m; ++i) {
            for (int j = 2; j < n; ++j) {
                bool feasible = true;
                int left = i - 2, up = j - 2, total = 0;
                for (int k = 0; k < 3; k++) {
                    if (!feasible) break;
                    for (int l = 0; l < 3; l++) {
                        total += image[i - k][j - l];
                        if (!feasible) break;
                        int x = i - k, y = j - l;
                        for (int d = 0; d < 4; d++) {
                            int x2 = x + dir[d], y2 = y + dir[d + 1];
                            if (x2 < left || x2 > i || y2 < up || y2 > j) continue;
                            if (abs(image[x][y] - image[x2][y2]) > threshold) {
                                feasible = false;
                                break;
                            }
                        }

                    }
                }
                if (feasible) {
                    for (int k = 0; k < 3; k++) {
                        for (int l = 0; l < 3; l++) {
                            num[i - k][j - l][0]++;
                            num[i - k][j - l][1] += total / 9;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (num[i][j][0]) {
                    res[i][j] = num[i][j][1] / num[i][j][0];
                }
            }
        }
        return res;
    }
};