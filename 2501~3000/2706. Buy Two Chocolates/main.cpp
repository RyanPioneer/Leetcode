/**
 * Source: jpeg.ly/LgDfj
 * Date: 2023/12/20
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 81.59% of C++ online submissions
 * Memory Usage: 46.93 MB, less than 58.30% of C++ online submissions
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
const int MX = 101;


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = MX, b = MX;
        for (auto &p: prices) {
            if (p < a) {
                b = a;
                a = p;
            } else if (p < b) {
                b = p;
            }
        }
        return a + b <= money ? money - a - b : money;
    }
};