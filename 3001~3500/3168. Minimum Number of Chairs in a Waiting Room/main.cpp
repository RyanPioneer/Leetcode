/**
 * Source: t.ly/_MYoX
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.94 MB, less than 40.00% of C++ online submissions
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
    int minimumChairs(string s) {
        int res = 0, chair = 0;
        for (auto &c: s) {
            if (c == 'E') chair++;
            else chair--;
            res = max(res, chair);
        }
        return res;
    }
};