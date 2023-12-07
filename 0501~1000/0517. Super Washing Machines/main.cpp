/**
 * Source: is.gd/ntcVce
 * Date: 2023/12/5
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 63.29% of C++ online submissions
 * Memory Usage: 13.17 MB, less than 96.20% of C++ online submissions
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
    int findMinMoves(vector<int>& machines) {
        if (accumulate(begin(machines), end(machines), 0) % SZ(machines) != 0) return -1;
        int sz = SZ(machines), diff = 0;
        int res = 0, num = accumulate(begin(machines), end(machines), 0) / sz;
        for (auto &i: machines) {
            int height = i - num;
            diff += height;
            res = max({res, abs(diff), height});
        }
        return res;
    }
};