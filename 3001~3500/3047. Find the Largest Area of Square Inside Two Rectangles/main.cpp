/**
 * Source: is.gd/xcxPoM
 * Date: 2024/2/28
 * Skill:
 * Ref:
 * Runtime: 198 ms, faster than 50.54% of C++ online submissions
 * Memory Usage: 58.80 MB, less than 49.56% of C++ online submissions
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
#define ll long long


class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int c = max(bottomLeft[i][0], bottomLeft[j][0]);
                int d = max(bottomLeft[i][1], bottomLeft[j][1]);
                int e = min(topRight[i][0], topRight[j][0]);
                int f = min(topRight[i][1], topRight[j][1]);
                if (e > c && f > d) {
                    ll len = min(e - c, f - d);
                    res = max(res, len * len);
                }
            }
        }
        return res;
    }
};