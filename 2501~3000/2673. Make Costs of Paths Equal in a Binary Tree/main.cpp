/**
 * Source: ibit.ly/_pSLp
 * Date: 2023/10/5
 * Skill:
 * Runtime: 133 ms, faster than 94.09% of C++ online submissions
 * Memory Usage: 135.57 MB, less than 22.60% of C++ online submissions
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
    int minIncrements(int n, vector<int>& cost) {
        int res = 0;
        for (int i = n / 2; i > 0; i--) {
            int diff = abs(cost[i * 2 - 1] - cost[i * 2]);
            res += diff;
            cost[i - 1] += max(cost[i * 2 - 1], cost[i * 2]);
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}