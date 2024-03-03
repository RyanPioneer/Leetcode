/**
 * Source: is.gd/qVv9tw
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 43 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 41.08 MB, less than 60.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n == nums.length <= 2 * 10 ** 4
 *      0 <= nums[i] <= 10 ** 9
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
#define ll long long

const int MX = 2e4+10;


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> adj_list[MX];
        for (auto &e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

    }
};