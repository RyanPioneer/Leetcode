/**
 * Source: t.ly/fVddk
 * Date: 2023/10/14
 * Skill:
 * Runtime: 38 ms, faster than 48.13% of C++ online submissions
 * Memory Usage: 10.24 MB, less than 71.12% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        int sz = aliceArrows.size(), cur_max = -1, max_mask = 0;
        vector<int> res(sz);
        for (int i = 0; i < (1 << sz); i++) {
            int score = 0, cost = 0;
            for (int j = 0; j < sz; j++) {
                if (((i >> j) & 1) != 0) {
                    score += j;
                    cost += aliceArrows[j] + 1;
                }
            }
            if (cost <= numArrows && score > cur_max) {
                cur_max = score;
                max_mask = i;
            }
        }
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
}