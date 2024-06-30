/**
 * Source: ibit.ly/mW62Z
 * Date: 2024/6/30
 * Skill:
 * Ref:
 * Runtime: 106 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 94.42 MB, less than 75.00% of C++ online submissions
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
const int MX = 2e5+10;


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        int zero[2] = {0}, one[2] = {0};
        for (auto &i: nums) {
            i %= 2;
            if (i == 0) {
                zero[0]++;
                one[0] = max(one[0], one[1] + 1);
            } else {
                zero[1]++;
                one[1] = max(one[1], one[0] + 1);
            }
        }
        for (int i = 0; i < 2; i++) {
            res = max({res, zero[i], one[i]});
        }
        return res;
    }
};