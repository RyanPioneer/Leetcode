/**
 * Source: ibit.ly/reBVt
 * Date: 2024/7/1
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 94.12% of C++ online submissions
 * Memory Usage: 11.66 MB, less than 94.12% of C++ online submissions
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
    int minBuildTime(vector<int>& blocks, int split) {
        sort(begin(blocks), end(blocks));
        int lo = 0, hi = INT32_MAX / 2, n = blocks.size();

        while (lo < hi) {
            int mid = (lo + hi) / 2, mid2 = (lo + hi) / 2;
            int num = 1;
            bool check = true;
            for (int i = n - 1; i >= 0; i--) {
                int dis = ((mid - blocks[i]) / split);
                for (int j = 0; j < dis && num < i + 1; j++) {
                    num *= 2;
                    mid -= split;
                }
                num--;
                if ((i > 0 && num == 0) || mid < blocks[i]) {
                    check = false;
                    break;
                }
                if (num >= i) break;
            }
            if (check) hi = mid2;
            else lo = mid2 + 1;
        }
        return hi;
    }
};