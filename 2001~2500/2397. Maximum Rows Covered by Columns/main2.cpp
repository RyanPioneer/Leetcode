/**
 * Source: twtr.to/vXdYq
 * Date: 2023/10/18
 * Skill:
 * Runtime: 6 ms, faster than 63.23% of C++ online submissions
 * Memory Usage: 8.72 MB, less than 63.68% of C++ online submissions
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
        function<int(int)> helper;
        helper = [&](int num) {
            int total = 0;
            if (__builtin_popcount(num) != numSelect)
                return 0;
            for (int i = 0; i < m; i++)
                if ((rows[i] & num) == rows[i])
                    total++;
            return total;
        };

        for (int i = 0; i < (1 << n); i++)
            res = max(res, helper(i));
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