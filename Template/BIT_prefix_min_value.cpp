/**
 * Source: t.ly/Su_5A
 * Date: 2023/11/11
 * Skill:
 * Runtime: 459 ms, faster than 84.77% of C++ online submissions
 * Memory Usage: 202.28 MB, less than 73.51% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;

#define ll long long

typedef pair<int, int> pairs;

const int MX = 101;


class BIT {
public:
    vector<int> arr;
    int n;
    BIT(int x) {
        n = x;
        arr.resize(x, INT32_MAX / 2);
    }

    void update(int index, int value) {
        while (index < n) {
            arr[index] = min(arr[index], value);
            index += index & -index;
        }
    }

    int query_min(int index) {
        int num = arr[index];
        while (index > 0) {
            num = min(arr[index], num);
            index -= index & -index;
        }
        return num;
    }
};

class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<BIT *> rows, cols;
        for (int i = 0; i < m; i++) rows.push_back(new BIT(n + 2));
        for (int i = 0; i < n; i++) cols.push_back(new BIT(m + 2));
        rows[m - 1]->update(n, 0);
        cols[n - 1]->update(m, 0);
        for (int i = n - 1; i > 0; i--) {
            if (grid[m - 1][i - 1] == 0) continue;
            int right = min(i + grid[m - 1][i - 1], n);
            int num = rows[m - 1]->query_min(right) + 1;
            rows[m - 1]->update(i, num);
            cols[i - 1]->update(m, num);
        }
        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) continue;
                int right = min(j + grid[i][j], n - 1);
                int down = min(i + grid[i][j], m - 1);
                int num = rows[i]->query_min(right + 1) + 1;
                num = min(num, cols[j]->query_min(down + 1) + 1);
                rows[i]->update(j + 1, num);
                cols[j]->update(i + 1, num);
            }
        }
        return rows[0]->query_min(1) + 1 < INT32_MAX / 2 ? rows[0]->query_min(1) + 1 : -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{3,4,2,1}, {4,2,3,1},{2,1,0,0},{2,4,0,0}};
    vector<int> nums{2,3,5};
    int res = s.minimumVisitedCells(arr);
    cout << res;
}