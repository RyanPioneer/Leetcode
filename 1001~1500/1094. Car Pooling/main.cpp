/**
 * Source: is.gd/KH6g5a
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 97.63% of C++ online submissions
 * Memory Usage: 10.70 MB, less than 79.46% of C++ online submissions
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
const int MX = 1e3 + 1;


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int diff_array[MX] = {0}, cur_num = 0;
        for (auto &i: trips) {
            diff_array[i[1]] += i[0];
            diff_array[i[2]] -= i[0];
        }
        for (int i = 0; i < MX; ++i) {
            cur_num += diff_array[i];
            if (cur_num > capacity) return false;
        }
        return true;
    }
};