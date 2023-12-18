/**
 * Source: jpeg.ly/KPoM8
 * Date: 2023/12/18
 * Skill:
 * Ref:
 * Runtime: 75 ms, faster than 69.23% of C++ online submissions
 * Memory Usage: 51.99 MB, less than 46.15% of C++ online submissions
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

vector<int> pal;

auto init = [] {
    pal.push_back(0);
    for (int base = 1; base < 1e5; base *= 10) {
        for (int odd = base; odd < base * 10; odd++) {
            int num = odd;
            for (int j = odd / 10; j; j /= 10) {
                num *= 10;
                num += j % 10;
            }
            pal.push_back(num);
        }
        if (base < 1e4) {
            for (int even = base; even < base * 10; even++) {
                int num = even;
                for (int j = even; j; j /= 10) {
                    num *= 10;
                    num += j % 10;
                }
                pal.push_back(num);
            }
        }
    }
    pal.push_back(1000000001);
    return 0;
}();

class Solution {
public:
    long long minimumCost(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int len = SZ(nums);
        int mid = len % 2 == 1 ? nums[len / 2] : (nums[len / 2 - 1] + nums[len / 2]) / 2;
        auto up = lower_bound(begin(pal), end(pal), mid);
        auto lo = prev(up);

        auto cost = [&](int num) {
            ll diff = 0;
            for (auto &i: nums) {
                diff += abs(i - num);
            }
            return diff;
        };

        return min(cost(*up), cost(*lo));
    }
};