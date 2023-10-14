/**
 * Source: t.ly/fVddk
 * Date: 2023/10/14
 * Skill:
 * Runtime: 11 ms, faster than 77.01% of C++ online submissions
 * Memory Usage: 10.48 MB, less than 56.15% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      aliceArrows.length == bobArrows.length == 12
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
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int sz = aliceArrows.size(), max_score = -1, max_mask = 0;
        vector<int> res(sz);
        function<void(int,int,int,int)> dfs;

        dfs = [&](int idx, int cur_mask, int arrow_num, int cur_score) {
            if (cur_score > max_score && arrow_num >= 0) {
                max_mask = cur_mask;
                max_score = cur_score;
            }
            if (idx == 0 || arrow_num < 0)
                return;
            dfs(idx - 1, cur_mask, arrow_num, cur_score);
            dfs(idx - 1, cur_mask + (1 << idx), arrow_num - aliceArrows[idx] - 1, cur_score + idx);
        };
        dfs(sz - 1, 0, numArrows, 0);
        for (int i = sz - 1; i > 0; i--)
            if (((max_mask >> i) & 1) != 0) {
                res[i] = aliceArrows[i] + 1;
                numArrows -= res[i];
            }
        res[0] = numArrows;
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int,int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}