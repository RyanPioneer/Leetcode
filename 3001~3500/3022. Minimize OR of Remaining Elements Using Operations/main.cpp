/**
 * Source: jpeg.ly/Vrpal
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime:  119ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 71.64 MB, less than 60.00% of C++ online submissions
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
    int minOrAfterOperations(vector<int>& nums, int k) {
        int res = 0;
        for (int bit = 29; bit >= 0; bit--) {
            int cnt = 0, and_res = -1;
            res |= 1 << bit;
            for (auto &i: nums) {
                and_res &= i & res;
                if (and_res) cnt++;
                else and_res = -1;
            }
            if (cnt > k) res -= 1 << bit;
        }
        return (1 << 30) - 1 - res;
    }
};