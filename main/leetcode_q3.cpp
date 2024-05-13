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
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef array<int, 3> AI3;
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 1e3 + 10;


class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = INT32_MIN;
        int premin[MX][MX];
        fill(premin[0], premin[MX - 1] + MX, INT32_MAX / 2);
        premin[1][1] = grid[0][0];
        for (int i = 2; i <= m; i++) {
            premin[i][1] = min(premin[i - 1][1], grid[i - 1][0]);
        }
        for (int i = 2; i <= n; i++) {
            premin[1][i] = min(premin[1][i - 1], grid[0][i - 1]);
        }
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                premin[i][j] = min({premin[i - 1][j], premin[i][j - 1], grid[i - 1][j - 1]});
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                res = max(res, grid[i - 1][j - 1] - min(premin[i - 1][j], premin[i][j - 1]));
            }
        }
        return res;
    }
};