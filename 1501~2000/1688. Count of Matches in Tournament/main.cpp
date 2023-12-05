/**
 * Source: jpeg.ly/nxpFT
 * Date: 2023/12/5
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.53 MB, less than 13.68% of C++ online submissions
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
#define ll long long
ll mod = 1e9+7;
const int MX = 1001;


class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n > 1) {
            res += n / 2;
            n = n / 2 + n % 2;
        }
        return res;
    }
};