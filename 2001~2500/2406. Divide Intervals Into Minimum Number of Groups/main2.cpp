/**
 * Source: https://rb.gy/s2ay7
 * Date: 2023/9/13
 * Skill:
 * Runtime: 469 ms, faster than 41.38% of C++ online submissions
 * Memory Usage: 118.20 MB, less than 37.20% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for (auto& i: intervals) {
            diff[i[0]]++;
            diff[i[1] + 1]--;
        }
        int cur = 0, res = 0;
        for (auto& [time, num]: diff) {
            cur += num;
            res = max(res, cur);
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}