/**
 * Source: t.ly/UXJtZ
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 20.60 MB, less than 79.67% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= m, n <= 500
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture)
    {
        int m = picture.size(), n = picture[0].size(), res = 0;
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1) {
                    res++;
                }
            }
        }
        return res;
    }
};
