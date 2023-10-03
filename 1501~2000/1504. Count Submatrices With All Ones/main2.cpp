/**
 * Source: ibit.ly/4t8C3
 * Date: 2023/10/3
 * Skill:
 * Runtime: 104 ms, faster than 33.28% of C++ online submissions
 * Memory Usage: 14.78 MB, less than 49.02% of C++ online submissions
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
        vector<int> histogram(n);
        for (int bottom = 0; bottom < m; ++bottom) {
            fill(begin(histogram), end(histogram), 0);
            for (int up = bottom; up >= 0; up--) {
                int cur_num = 0;
                for (int idx = 0; idx < n; ++idx) {
                    histogram[idx] += mat[up][idx];
                    if (histogram[idx] == bottom - up + 1)
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