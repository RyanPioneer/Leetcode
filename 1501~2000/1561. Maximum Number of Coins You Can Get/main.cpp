/**
 * Source: jpeg.ly/S9d8K
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 93 ms, faster than 55.32% of C++ online submissions
 * Memory Usage: 53.68 MB, less than 93.07% of C++ online submissions
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
    int maxCoins(vector<int>& piles) {
        sort(begin(piles), end(piles));
        int sz = SZ(piles), res = 0;
        for (int idx = sz - 2; idx >= sz / 3; idx -= 2) {
            res += piles[idx];
        }
        return res;
    }
};