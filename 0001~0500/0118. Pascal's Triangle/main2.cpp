/** 
 * Source: https://leetcode.com/problems/pascals-triangle/
 * Date: 2022/7/19
 * Skill:
 * Runtime: 0 ms, faster than 100.00% 
 * Memory Usage: 6.7 MB, less than 31.97%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= numRows <= 30
 */

#include <iostream>
#include <vector> 
#include <utility>
#include <unordered_map>
//#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].resize(1,1);
        for (int i = 1; i < numRows; i++) {
            res[i].resize(i+1, 1);
            for (int j = 1; j < i; j++)
                res[i][j] = res[i-1][j-1]+res[i-1][j];
        }
        return res;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    //std::cout.tie(nullptr);
    return nullptr;
}();