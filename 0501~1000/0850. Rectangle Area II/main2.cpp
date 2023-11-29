/**
 * Source: is.gd/sODYmr
 * Date: 2023/11/29
 * Skill: Discretization
 * Ref:
 * Runtime: 17 ms, faster than 37.16% of C++ online submissions
 * Memory Usage: 10.79 MB, less than 32.43% of C++ online submissions
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
#define ll long long
typedef pair<int, int> PII;
ll mod = 1e9+7;
const int MX = 201;


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        set<int> x_set, y_set;
        for (auto &r: rectangles) {
            x_set.insert(r[0]);
            x_set.insert(r[2]);
            y_set.insert(r[1]);
            y_set.insert(r[3]);
        }
        int m = SZ(x_set), n = SZ(y_set);
        vector<int> x_pos(begin(x_set), end(x_set));
        vector<int> y_pos(begin(y_set), end(y_set));
        vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
        for (auto &r: rectangles) {
            int left = lower_bound(begin(x_pos), end(x_pos), r[0]) - begin(x_pos);
            int right = lower_bound(begin(x_pos), end(x_pos), r[2]) - begin(x_pos);
            int down = lower_bound(begin(y_pos), end(y_pos), r[1]) - begin(y_pos);
            int up = lower_bound(begin(y_pos), end(y_pos), r[3]) - begin(y_pos);
            for (int x = left; x < right; x++) {
                for (int y = down; y < up; y++) {
                    grid[x][y] = 1;
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    res += (ll)(x_pos[i + 1] - x_pos[i]) * (y_pos[j + 1] - y_pos[j]);
                }
            }
        }
        return res % mod;
    }
};