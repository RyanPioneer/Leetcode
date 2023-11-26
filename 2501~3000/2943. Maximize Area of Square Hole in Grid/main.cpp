/**
 * Source: is.gd/7ftVD9
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 27.86 MB, less than 100.00% of C++ online submissions
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


class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int mx_h = 1, mx_v = 1, num = 1;
        for (int i = 1; i < SZ(hBars); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                num++;
                mx_h = max(mx_h, num);
            } else {
                num = 1;
            }
        }
        num = 1;
        for (int i = 1; i < SZ(vBars); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                num++;
                mx_v = max(mx_v, num);
            } else {
                num = 1;
            }
        }
        int len = 1 + min(mx_h, mx_v);
        return len * len;
    }
};