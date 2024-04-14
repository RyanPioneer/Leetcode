/**
 * Source: is.gd/Ws1fFc
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.48 MB, less than 85.19% of C++ online submissions
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
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        while (numBottles >= numExchange) {
            res++;
            numBottles -= numExchange++ - 1;
        }
        return res;
    }
};