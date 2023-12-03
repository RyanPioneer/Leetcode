/**
 * Source: jpeg.ly/zsRQe
 * Date: 2023/12/3
 * Skill:
 * Ref:
 * Runtime: 5 ms, faster than 43.38% of C++ online submissions
 * Memory Usage: 11.60 MB, less than 88.87% of C++ online submissions
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
    int minPatches(vector<int>& nums, int n) {
        sort(begin(nums), end(nums));
        ll num = 0, res = 0;
        for (auto &i: nums) {
            while (num + 1 < i && num < n) {
                num += num + 1;
                res++;
            }
            if (num >= n) return res;
            num += i;
        }
        while (num  < n) {
            num += num + 1;
            res++;
        }
        return res;
    }
};