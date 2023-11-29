/**
 * Source: is.gd/sODYmr
 * Date: 2023/11/29
 * Skill: Discretization, Sweep line
 * Ref:
 * Runtime: 23 ms, faster than 33.11% of C++ online submissions
 * Memory Usage: 12.89 MB, less than 20.27% of C++ online submissions
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


class Diff2d {
public:
    int m, n;
    vector<vector<int>> diff, height;
    Diff2d(int m, int n) : m(m), n(n) {
        diff.resize(m + 1);
        height.resize(m + 1);
        for (int i = 0; i <= m; i++) {
            diff[i].resize(n + 1);
            height[i].resize(n + 1);
        }
    }

    void set(int left, int right, int down, int up, int h) {
        diff[left][down] += h;
        diff[left][up + 1] -= h;
        diff[right + 1][down] -= h;
        diff[right + 1][up + 1] += h;
    }

    void calculate() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                height[i][j] = diff[i][j];
                height[i][j] += i > 0 ? height[i - 1][j] : 0;
                height[i][j] += j > 0 ? height[i][j - 1] : 0;
                height[i][j] -= (i > 0 && j > 0) ? height[i - 1][j - 1] : 0;
            }
        }
    }
};

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
        vector<int> row(begin(x_set), end(x_set));
        vector<int> col(begin(y_set), end(y_set));
        Diff2d *grid = new Diff2d(m, n);
        unordered_map<int, int> x2idx, y2idx;
        for (int i = 0; i < m; i++) x2idx[row[i]] = i;
        for (int i = 0; i < n; i++) y2idx[col[i]] = i;
        for (auto &r: rectangles) {
            int left = x2idx[r[0]];
            int right = x2idx[r[2]];
            int down = y2idx[r[1]];
            int up = y2idx[r[3]];
            grid->set(left, right - 1, down, up - 1, 1);
        }

        grid->calculate();
        ll res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid->height[i][j] > 0) {
                    res += (ll)(row[i + 1] - row[i]) * (col[j + 1] - col[j]);
                }
            }
        }
        return res % mod;
    }
};