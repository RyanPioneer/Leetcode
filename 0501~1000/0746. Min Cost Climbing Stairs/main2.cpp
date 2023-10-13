/**
 * Source: ibit.ly/auWlF
 * Date: 2023/10/13
 * Skill:
 * Runtime: 4 ms, faster than 61.59% of C++ online submissions
 * Memory Usage: 13.99 MB, less than 37.30% of C++ online submissions
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
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        for (int i = 2; i < sz; i++)
            cost[i] += min(cost[i - 1], cost[i - 2]);
        return min(cost[sz - 1], cost[sz - 2]);
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}