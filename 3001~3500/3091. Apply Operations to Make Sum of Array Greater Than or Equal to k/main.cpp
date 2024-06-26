/**
 * Source: is.gd/OxxOcD
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.43 MB, less than 11.16% of C++ online submissions
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
    int minOperations(int k) {
        int res = INT32_MAX;
        for (int i = 1; i <= k; i++) {
            res = min(res, i - 1 + (k - i) / i + ((k - i) % i != 0));
        }
        return res;
    }
};