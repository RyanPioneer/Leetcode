/**
 * Source: t.ly/yRVqu
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 361 ms, faster than 25.76% of C++ online submissions
 * Memory Usage: 202.67 MB, less than 45.45% of C++ online submissions
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


class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {
        int n = y.size(), curNum = 0, res = 0;
        int pos = 0, dir = y[1] - y[0];
        map<float, int> mp;



        for (auto &i: mp) {
            curNum += i.second;
            res = max(res, curNum);
        }
        return res;
    }
};