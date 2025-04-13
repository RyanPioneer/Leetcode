/**
 * Source: tinyurl.com/y3reu3y2
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 93.67% of C++ online submissions
 * Memory Usage: 11.78 MB, less than 3.17% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= rows, cols <= 100
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MX = 1e3;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
   public:
    int get(int row, int col);
    vector<int> dimensions();
};

class Solution {
   public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto v = binaryMatrix.dimensions();
        int m = v[0], n = v[1], dp[MX];
        fill(dp, dp + MX, -1);
        int l = 0, r = n - 1;

        auto check = [&](int col) {
            if (dp[col] != -1) {
                return dp[col];
            }
            dp[col] = 0;
            for (int i = 0; i < m; i++) {
                if (binaryMatrix.get(i, col) == 1) {
                    dp[col] = 1;
                    break;
                }
            }
            return dp[col];
        };

        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return check(l) ? l : -1;
    }
};
