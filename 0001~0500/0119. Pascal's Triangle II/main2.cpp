/** 
 * Source: https://leetcode.com/problems/pascals-triangle-ii/
 * Date: 2021/7/12
 * Constraints: 0 <= rowIndex <= 33
 * Using Binomial Coefficients Recurrence Relationship
 * Using C(m, n) = (m - n + 1) / n * C(m, n - 1)
 * Time Complexity: O(rowIndex)
 * Space Complexity: O(rowIndex)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans(rowIndex + 1, 1);
        for(int i = 1; i <= (rowIndex + 1) / 2; i ++)
            ans[i] = ans[rowIndex - i] = (long long)(rowIndex - i + 1) * ans[i - 1] / i;
        return ans;
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();