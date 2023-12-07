/**
 * Source: jpeg.ly/KDkzo
 * Date: 2023/12/6
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.25 MB, less than 70.53% of C++ online submissions
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
    int totalMoney(int n) {
        int res = 0, start = 1;
        while (n > 7) {
            res += (start * 2 + 6) * 7 / 2;
            start++;
            n -= 7;
        }
        res += (start * 2 + n - 1) * n / 2;
        return res;
    }
};