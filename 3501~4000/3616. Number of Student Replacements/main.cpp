/**
 * Source: t.ly/xbIEI
 * Date: 2025/7/25
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 181.72 MB, less than 75.76% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

class Solution {
   public:
    int totalReplacements(vector<int>& ranks) {
        int res = 0, mi = ranks[0];
        for (int i = 1; i < ranks.size(); i++) {
            if (ranks[i] < mi) {
                res++;
            }
            mi = min(mi, ranks[i]);
        }
        return res;
    }
};