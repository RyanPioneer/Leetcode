/**
 * Source: ibit.ly/47ixS
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 459 ms, faster than 73.68% of C++ online submissions
 * Memory Usage: 151.38 MB, less than 89.47% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 1e4+10, MOD = 1e9+7;


class Solution {
public:
    double maxPrice(vector<vector<int>>& items, int capacity) {
        double res = 0;
        sort(begin(items), end(items), [](const vector<int> &a, const vector<int> &b) {
            return (double)a[0]/a[1] > (double)b[0]/b[1];
        });
        for (auto &i: items) {
            int c = min(capacity, i[1]);
            capacity -= c;
            res += (double)i[0] * c / i[1];
        }
        return capacity == 0 ? res : -1;
    }
};