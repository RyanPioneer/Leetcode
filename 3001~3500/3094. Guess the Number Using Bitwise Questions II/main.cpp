/**
 * Source: ibit.ly/5vn63
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.45 MB, less than 21.23% of C++ online submissions
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

const int MX = 1e3+10;


int commonBits(int num);


class Solution {
public:
    int findNumber() {
        int res = 0, cnt = commonBits(0);
        for (int i = 29; i >= 0; i--) {
            int j = commonBits(1 << i);
            if (j > cnt) {
                res |= 1 << i;
            }
            j = commonBits(1 << i);
        }
        return res;
    }
};