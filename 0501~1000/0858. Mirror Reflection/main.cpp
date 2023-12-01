/**
 * Source: is.gd/BAWMXk
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.25 MB, less than 72.60% of C++ online submissions
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
    int mirrorReflection(int p, int q) {
        // 0: (2 * t + 1) * q % (2 * p) = 0
        // 1: (2 * t + 1) * q / p % 2 = 1
        // 2: 2 * t * q / p % 2 = 1
        int p_num = 0, q_num = 0;
        while (p % 2 == 0) {
            p_num++;
            p >>= 1;
        }
        while (q % 2 == 0) {
            q_num++;
            q >>= 1;
        }
        if (p_num > q_num) return 2;
        else if (p_num == q_num) return 1;
        else return 0;
    }
};