/**
 * Source: ibit.ly/SZiL8
 * Date: 2023/10/2
 * Skill:
 * Runtime: 256 ms, faster than 6.01% of C++ online submissions
 * Memory Usage: 116.38 MB, less than 5.62% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        map<int, int> cnt;
        for (auto i: nums)
            cnt[i]++;
        ll res = begin(cnt)->second, cur_sum = 0, cur_num = begin(cnt)->second;
        auto left = begin(cnt);
        for (auto i = next(begin(cnt)); i != end(cnt); i = next(i)) {
            int diff = i->first - prev(i)->first, prev_num = prev(i)->first;
            while (diff * cur_num + cur_sum > k) {
                if (diff * (cur_num - left->second) + cur_sum - (prev_num - left->first)
                                                                * left->second > k) {
                    cur_sum -= (prev_num - left->first) * left->second;
                    cur_num -= left->second;
                    left = next(left);
                } else {
                    int lo = 1, hi = left->second;
                    while (lo < hi) {
                        int mid = (lo + hi) / 2;
                        if (diff * (cur_num - mid) + cur_sum -
                            (prev_num - left->first) * mid > k)
                            lo = mid + 1;
                        else
                            hi = mid;
                    }
                    left->second -= lo;
                    cur_num -= lo;
                    cur_sum -= (prev_num - left->first) * lo;
                }
            }
            if (left->second == 0)
                left = next(left);
            cur_sum += diff * cur_num;
            cur_num += i->second;
            res = max(res, cur_num);
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}