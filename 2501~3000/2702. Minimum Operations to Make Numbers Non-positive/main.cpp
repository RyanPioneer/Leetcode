/**
 * Source: t.ly/CPE3y
 * Date: 2024/4/25
 * Skill:
 * Ref:
 * Runtime: 106 ms, faster than 82.76% of C++ online submissions
 * Memory Usage: 76.26 MB, less than 41.38% of C++ online submissions
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


class Solution {
public:
    int minOperations(vector<int>& nums, int x, int y) {
        int left = 0, right = INT32_MAX, diff = x - y;

        while (left < right) {
            ll mid = (left + right) / 2, cnt = 0;
            ll num = mid * y;

            for (auto &i: nums) {
                if (i > num) {
                    cnt += (i - num) / diff + ((i - num) % diff != 0);
                }
            }
            if (cnt > mid) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};