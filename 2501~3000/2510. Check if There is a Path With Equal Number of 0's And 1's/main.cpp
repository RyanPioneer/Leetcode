/**
 * Source: ibit.ly/24yHO
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 87.72% of C++ online submissions
 * Memory Usage: 11.73 MB, less than 97.37% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)

const int MX = 110;

int mi[MX][MX], mx[MX][MX];

class Solution {
public:
    bool isThereAPath(vector<vector<int>>& arr) {
        int n = arr.size(), m = arr[0].size();
        if ((n + m - 1) & 1) {
            return false;
        }
        int h = (n + m - 1) / 2;
        For(i, 1, n)
            For(j, 1, m)
                mx[i][j] = max(mx[i][j-1], mx[i-1][j]) + (arr[i - 1][j - 1] == 1 ? 1 : 0);

        For(i, 2, n) mi[i][0] = 0x3f3f3f3f;
        For(i, 2, m) mi[0][i] = 0x3f3f3f3f;
        For(i, 1, n)
            For(j, 1, m)
                mi[i][j] = min(mi[i][j-1], mi[i-1][j]) + (arr[i - 1][j - 1] == 1 ? 1 : 0);

        if (mi[n][m] <= h && h <= mx[n][m]) return true;
        else return false;
    }
};