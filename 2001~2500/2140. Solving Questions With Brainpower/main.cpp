/**
 * Source: https://rb.gy/s17u8
 * Date: 2023/9/18
 * Skill:
 * Runtime: 317 ms, faster than 23.45% of C++ online submissions
 * Memory Usage: 119.08 MB, less than 61.29% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ll res = 0;
        map<int, ll> nums;
        for (int i = 0; i < questions.size(); i++) {
            auto it = nums.upper_bound(i);
            ll num = questions[i][0] + (it == begin(nums) ? 0 : prev(it)->second);
            res = max(res, num);
            int next_pos = i + questions[i][1] + 1;
            auto it2 = nums.upper_bound(next_pos);
            while (it2 != end(nums) && it2->second <= num) {
                auto tmp = it2;
                it2 = next(it2);
                nums.erase(tmp);
            }
            it2 = nums.upper_bound(next_pos);
            if (it2 == begin(nums) || prev(it2)->second < num)
                nums[next_pos] = num;
            while (nums.size() > 1 && next(begin(nums))->first <= i)
                nums.erase(begin(nums));
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr{{0, 1, 0, 0, 0},
                            {0, 1, 0, 1, 0},
                            {0, 0, 0, 1, 0}};
    map<int, ll> nums;
    nums[2] = 2;
    nums[3] = 2;
    auto it = nums.upper_bound(0);
    cout << (it == begin(nums)) << endl;
}