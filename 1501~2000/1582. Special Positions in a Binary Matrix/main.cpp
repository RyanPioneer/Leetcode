/**
 * Source: jpeg.ly/AcoB5
 * Date: 2023/12/13
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 90.00% of C++ online submissions
 * Memory Usage: 13.10 MB, less than 95.53% of C++ online submissions
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
const int MX = 101;


class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = SZ(mat), n = SZ(mat[0]), rows[MX] = {0}, cols[MX] = {0}, res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rows[i] += mat[i][j];
                cols[j] += mat[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1) res++;
            }
        }
        return res;
    }
};