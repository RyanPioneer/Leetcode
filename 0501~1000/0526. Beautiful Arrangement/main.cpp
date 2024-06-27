/**
 * Source: ibit.ly/oo9lK
 * Date: 2024/6/27
 * Skill:
 * Ref:
 * Runtime: 6 ms, faster than 92.45% of C++ online submissions
 * Memory Usage: 7.47 MB, less than 50.99% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *  1 <= n <= 15
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
const int MX = 1 << 16;


class Solution {
public:
    int countArrangement(int n) {
        int cnt[MX] = {1};
        for (int state = 1; state <= (1 << n) - 1; state++) {
            int bitNum = __builtin_popcount(state);
            for (int num = 0; num < n; num++) {
                if (((state >> num) & 1) && ((num + 1) % bitNum == 0 || bitNum % (num + 1) == 0)) {
                    cnt[state] += cnt[state - (1 << num)];
                }
            }
        }
        return cnt[(1 << n) - 1];
    }
};