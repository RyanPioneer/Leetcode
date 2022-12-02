/** 
 * Source: https://leetcode.com/problems/rectangle-area/
 * Date: 2022/11/17
 * Skill: Math
 * Runtime: 5 ms, faster than 92.46%
 * Memory Usage: 5.9 MB, less than 75.43%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      -10^4 <= ax1 <= ax2 <= 10^4
 * 
 */

#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;


class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x1 = max(ax1, bx1);
        int x2 = min(ax2, bx2);
        int y1 = max(ay1, by1);
        int y2 = min(ay2, by2);
        int overlap_area = (x2>x1 && y2>y1)?(x2-x1)*(y2-y1):0;
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-overlap_area;
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