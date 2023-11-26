/**
 * Source: jpeg.ly/PQJMy
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 125 ms, faster than 85.58% of C++ online submissions
 * Memory Usage: 61.08 MB, less than 80.63% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long


class Solution {
public:
    long long minCost(vector<int>& nums, int x) {
        int len = SZ(nums);
        ll res = accumulate(begin(nums), end(nums), 0ll);
        ll cur_sum = res;
        vector<int> cur_min = nums;
        for (int i = 1; i < len; i++) {
            cur_sum += x;
            for (int j = 0; j < len; j++) {
                if (cur_min[j] > nums[(j + i) % len]) {
                    cur_sum -= nums[(j + i) % len] - cur_min[j];
                    cur_min[j] = nums[(j + i) % len];
                }
            }
            res = min(res, cur_sum);
        }
        return res;
    }
};