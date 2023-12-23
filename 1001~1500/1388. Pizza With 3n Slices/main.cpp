/**
 * Source: jpeg.ly/QAeOl
 * Date: 2023/12/23
 * Skill:
 * Ref: is.gd/gALSlM
 * Runtime: 4 ms, faster than 99.66% of C++ online submissions
 * Memory Usage: 8.40 MB, less than 99.66% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *  1 <= slices.length <= 500
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
const int MX = 501;


class Solution {
    int dp0[MX], dp1[MX];
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        return max(helper(0, n - 2, n / 3, slices), helper(1, n - 1, n / 3, slices));
    }
    int helper(int start, int end, int num, vector<int>& slices) {
        fill(dp0, dp0 + MX, 0);
        fill(dp1, dp1 + MX, 0);
        dp1[1] = slices[start];
        for (int i = start + 1; i <= end; i++) {
            for (int j = min(i - start + 1, num); j >= 1; j--) {
                dp0[j] = max(dp0[j], dp1[j]);
                dp1[j] = slices[i] + dp0[j - 1];
            }
        }
        return max(dp0[num], dp1[num]);
    }
};