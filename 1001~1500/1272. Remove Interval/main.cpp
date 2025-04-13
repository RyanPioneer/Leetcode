/**
 * Source: tinyurl.com/syvucrt
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime: 5 ms, faster than 79.37% of C++ online submissions
 * Memory Usage: 42.60 MB, less than 76.98% of C++ online submissions
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
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals,
                                       vector<int>& toBeRemoved) {
        vector<vector<int>> res;
        for (auto& i : intervals) {
            if (i[0] >= toBeRemoved[1]) {
                res.push_back(i);
            } else if (i[1] <= toBeRemoved[0]) {
                res.push_back(i);
            } else if (i[0] >= toBeRemoved[0] && i[1] <= toBeRemoved[1]) {
                continue;
            } else {
                if (i[0] < toBeRemoved[0]) {
                    res.push_back({i[0], toBeRemoved[0]});
                }
                if (i[1] > toBeRemoved[1]) {
                    res.push_back({toBeRemoved[1], i[1]});
                }
            }
        }
        return res;
    }
};
