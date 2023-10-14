/**
 * Source: t.ly/SkqIk
 * Date: 2023/10/14
 * Skill:
 * Runtime: 167 ms, faster than 93.54% of C++ online submissions
 * Memory Usage: 100.98 MB, less than 76.96% of C++ online submissions
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
    long long minimumRemoval(vector<int>& beans) {
        ll cur_sum = accumulate(begin(beans), end(beans), 0ll), cur_num = beans.size();
        ll res = cur_sum, prev_sum = 0, sz = beans.size();
        sort(begin(beans), end(beans));
        for (int i = 0; i < sz; i++) {
            res = min(res, prev_sum + cur_sum - beans[i] * (sz - i));
            prev_sum += beans[i];
            cur_sum -= beans[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}