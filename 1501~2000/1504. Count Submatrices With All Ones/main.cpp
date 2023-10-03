/**
 * Source: ibit.ly/4t8C3
 * Date: 2023/10/3
 * Skill:
 * Runtime: 161 ms, faster than 23.77% of C++ online submissions
 * Memory Usage: 15.52 MB, less than 19.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= m, n <= 150
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int res = 0, m = mat.size(), n = mat[0].size();
        vector<vector<int>> presum(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            presum[i + 1][1] = presum[i][1] + mat[i][0];
        for (int i = 0; i < n; i++)
            presum[1][i + 1] = presum[1][i] + mat[0][i];
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                presum[i + 1][j + 1] = mat[i][j] + presum[i + 1][j] + presum[i][j + 1] - presum[i][j];
        for (int left = 0; left < n; left++) {
            for (int right = left; right < n; right++) {
                int cur_num = 0;
                for (int i = 0; i < m; i++) {
                    int num = presum[i + 1][right + 1] - presum[i + 1][left] - presum[i][right + 1] + presum[i][left];
                    if (num == right - left + 1)
                        res += ++cur_num;
                    else
                        cur_num = 0;
                }
            }
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}