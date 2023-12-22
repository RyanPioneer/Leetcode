/**
 * Source: jpeg.ly/mR1NC
 * Date: 2023/12/19
 * Skill:
 * Ref:
 * Runtime: 41 ms, faster than 69.85% of C++ online submissions
 * Memory Usage: 22.26 MB, less than 21.54% of C++ online submissions
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
const int MX = 202;


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = SZ(img), n = SZ(img[0]), presum[MX][MX] = {0};
        for (int i = 0; i < m; i++) presum[i + 1][1] = presum[i][1] + img[i][0];
        for (int i = 0; i < n; i++) presum[1][i + 1] = presum[1][i] + img[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                presum[i + 1][j + 1] = presum[i + 1][j] + presum[i][j + 1] - presum[i][j] + img[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int left = max(j - 1, 0), right = min(j + 1, n - 1);
                int down = max(i - 1, 0), up = min(i + 1, m - 1);
                int num = (right - left + 1) * (up - down + 1);
                res[i][j] = (presum[up + 1][right + 1] - presum[down][right + 1] - presum[up + 1][left] + presum[down][left]) / num;
            }
        }
        return res;
    }
};