/**
 * Source: t.ly/w82El
 * Date: 2024/4/26
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.90 MB, less than 100.00% of C++ online submissions
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
    long long maxNumber(long long n) {
        int num = -1;
        while (n) {
            n >>= 1;
            num++;
        }
        return (1ll << num) - 1;
    }
};