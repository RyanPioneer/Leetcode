/** 
 * Source: https://leetcode.com/problems/pascals-triangle/
 * Date: 2021/7/12
 * Constraints: 1 <= numRows <= 30
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        for(int i = 2; i <= numRows; i++) {
            vector<int>local;
            local.push_back(ans[i-2][0]);
            for(int j = 1; j < i-1; j++) {
                local.push_back(ans[i-2][j-1]+ ans[i-2][j]);
            }
            local.push_back(ans[i-2][i-2]);
            ans.push_back(local);
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();