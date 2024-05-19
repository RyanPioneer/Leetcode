/**
 * Source: t.ly/g6ka5
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.38 MB, less than 100.00% of C++ online submissions
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
#define MK make_pair
#define SZ(X) ((int)(X).size())
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 31;
int c[MX][MX];

auto init = [] {
    for (int i = 0; i < MX; i++) {
        c[i][i] = c[i][0] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
    return 0;
}();

class Solution {
public:
    int waysToReachStair(int k) {
        int res = 0;
        for (int i = 0; i < 30; i++) {
            int m = (1 << i) - k;
            if (0 <= m && m <= i + 1) {
                res += c[i+1][m];
            }
        }
        return res;
    }
};