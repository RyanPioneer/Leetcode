/**
 * Source: jpeg.ly/Cm51j
 * Date: 2023/12/21
 * Skill:
 * Ref:
 * Runtime: 169 ms, faster than 95.00% of C++ online submissions
 * Memory Usage: 68.80 MB, less than 39.84% of C++ online submissions
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
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        vector<int> p;
        for (auto &i: points) {p.push_back(i[0]);}
        sort(begin(p), end(p));
        int res = 0;
        for (int i = 1; i < SZ(p); i++) {
            res = max(res, p[i] - p[i - 1]);
        }
        return res;
    }
};