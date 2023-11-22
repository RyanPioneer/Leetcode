/**
 * Source: https://rb.gy/at16m
 * Date: 2023/9/2
 * Skill:
 * Runtime: 200 ms, faster than 81.74% of C++ online submissions
 * Memory Usage: 97.33 MB, less than 55.55% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= k <= nums.length <= 10 ** 5
 *      -10 ** 4 <= nums[i] <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>
#include <deque>

using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        int m = nums.size(), length = 0;
        unordered_map<int, vector<int> > mymap;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < nums[i].size(); j++)
                mymap[i + j].push_back(nums[i][j]);
        while (mymap.find(length) != mymap.end()) {
            for (int j = mymap[length].size() - 1; j >= 0; j--)
                res.push_back(mymap[length][j]);
            length++;
        }
        return res;
    }
};