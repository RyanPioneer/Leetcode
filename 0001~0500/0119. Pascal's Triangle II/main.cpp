/** 
 * Source: https://leetcode.com/problems/pascals-triangle-ii/
 * Date: 2021/7/12
 * Constraints: 0 <= rowIndex <= 33
 * try to use only O(rowIndex) extra space
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex+1);
        ans[0] = 1;
        for(int i = 1; i <= rowIndex; i++) {
            ans[i] = ans[i-1];
            for(int j = i-1; j > 0; j--) 
                ans[j] = ans[j] + ans[j-1];
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