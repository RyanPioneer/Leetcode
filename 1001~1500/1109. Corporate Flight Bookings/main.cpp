/**
 * Source: twtr.to/Zwtif
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 158 ms, faster than 88.91% of C++ online submissions
 * Memory Usage: 69.35 MB, less than 50.96% of C++ online submissions
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
const int MX = 2 * 1e4 + 2;


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int diff[MX] = {0}, cur = 0;
        for (auto &i: bookings) {
            diff[i[0]] += i[2];
            diff[i[1] + 1] -= i[2];
        }
        vector<int> res;
        for (int i = 1; i <= n; i++) {
            cur += diff[i];
            res.push_back(cur);
        }
        return res;
    }
};