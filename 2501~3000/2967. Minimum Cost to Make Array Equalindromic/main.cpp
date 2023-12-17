/**
 * Source: jpeg.ly/KPoM8
 * Date: 2023/12/17
 * Skill:
 * Ref:
 * Runtime: 88 ms, faster than 53.85% of C++ online submissions
 * Memory Usage: 50.72 MB, less than 100.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int mid = nums.size() % 2 == 1 ? nums[SZ(nums) / 2] : (nums[SZ(nums) / 2 - 1] + nums[SZ(nums) / 2]) / 2;
        int up = find(mid, 1), down = find(mid, -1);
        ll res1 = 0, res2 = 0;
        for (auto &i: nums) {
            res1 += abs(i - up);
            res2 += abs(i - down);
        }
        return min(res1, res2);
    }
    int find(int n, int dir) {
        while (!check(n)) n += dir;
        return n;
    }
    bool check(int num) {
        int r = 0, n = num;
        while (n > 0) {
            r *= 10;
            r += n % 10;
            n /= 10;
        }
        return r == num;
    }
};