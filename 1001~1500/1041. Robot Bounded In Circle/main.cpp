/**
 * Source: ibit.ly/wgJB1
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.29 MB, less than 79.32% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
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


class Solution {
public:
    bool isRobotBounded(string instructions) {
        int cnt = 0;
        int x = 0, y = 0;
        for (auto &c: instructions) {
            if (c == 'L') cnt++;
            if (c == 'R') {
                cnt--;
                if (cnt < 0) cnt = 3;
            }
            if (c == 'G') {
                if (cnt % 4 == 0) {
                    y++;
                } else if (cnt % 4 == 1) {
                    x--;
                } else if (cnt % 4 == 2) {
                    y--;
                } else {
                    x++;
                }
            }
        }
        return cnt % 4 != 0 || (x == 0 && y == 0);
    }
};