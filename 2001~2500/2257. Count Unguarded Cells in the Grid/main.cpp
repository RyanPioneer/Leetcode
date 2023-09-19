/**
 * Source: https://rb.gy/mpsh5
 * Date: 2023/9/19
 * Skill:
 * Runtime: 698 ms, faster than 16.43% of C++ online submissions
 * Memory Usage: 229.42 MB, less than 11.27% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int res = 0;
        vector<vector<int>> grid(m, vector<int>(n, -1));
        vector<vector<int>> rows(m), cols(n);
        for (auto i: guards) {
            grid[i[0]][i[1]] = 0;
            rows[i[0]].push_back(i[1]);
            cols[i[1]].push_back(i[0]);
        }
        for (auto i: walls) {
            grid[i[0]][i[1]] = 1;
            rows[i[0]].push_back(i[1]);
            cols[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < m; i++)
            sort(begin(rows[i]), end(rows[i]));
        for (int i = 0; i < n; i++)
            sort(begin(cols[i]), end(cols[i]));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != -1)
                    continue;
                auto it = upper_bound(begin(rows[i]), end(rows[i]), j);
                if (it != end(rows[i]) && grid[i][*it] == 0)
                    continue;
                if (it != begin(rows[i]) && grid[i][*prev(it)] == 0)
                    continue;
                it = upper_bound(begin(cols[j]), end(cols[j]), i);
                if (it != end(cols[j]) && grid[*it][j] == 0)
                    continue;
                if (it != begin(cols[j]) && grid[*prev(it)][j] == 0)
                    continue;
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{0, 0},
                             {1, 1},
                             {2, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    int res = s.countUnguarded(4,6,arr1, arr2);
    cout << res << endl;
}