/**
 * Source: twtr.to/vXdYq
 * Date: 2023/10/18
 * Skill: Gosper's hack
 * Runtime: 2 ms, faster than 83.41% of C++ online submissions
 * Memory Usage: 8.82 MB, less than 52.91% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> rows(m, 0);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    rows[i] += (1 << j);

        int state = (1 << numSelect) - 1;
        while (state < (1 << n))
        {
            int count = 0;
            for (int x: rows)
                if ((state&x)==x)
                    count++;
            res = max(res, count);

            int c = state & - state;
            int r = state + c;
            state = (((r ^ state) >> 2) / c) | r;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}