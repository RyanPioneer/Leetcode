/**
 * Source: t.ly/340YB
 * Date: 2023/11/29
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.29 MB, less than 94.23% of C++ online submissions
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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n) {
            res ++;
            n &= n - 1;
        }
        return res;
    }
};