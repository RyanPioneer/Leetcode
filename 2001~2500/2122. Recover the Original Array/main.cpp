/**
 * Source: https://rb.gy/oackw
 * Date: 2023/9/15
 * Skill:
 * Runtime: 1609 ms, faster than 17.74% of C++ online submissions
 * Memory Usage: 394.76 MB, less than 53.22% of C++ online submissions
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
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> res;
        int sz = nums.size(), k;
        sort(begin(nums), end(nums));
        unordered_map<int, int> num2cnt;
        for(int i = 1; i < sz; i++) {
            if (nums[i] - nums[0] == 0 || (nums[i] - nums[0]) % 2 == 1 || nums[i] == nums[i - 1])
                continue;
            int t = (nums[i] - nums[0]) / 2, pairs = 0;
            num2cnt.clear();
            for (auto n: nums) {
                if (num2cnt[n - 2 * t] > 0) {
                    num2cnt[n - 2 * t]--;
                    pairs++;
                } else
                    num2cnt[n]++;
            }
            if (pairs == sz / 2) {
                k = t;
                break;
            }
        }
        num2cnt.clear();
        for (auto n: nums) {
            if (num2cnt[n - 2 * k] > 0)
                num2cnt[n - 2 * k]--;
            else {
                num2cnt[n]++;
                res.push_back(n + k);
            }
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<int> res = s.recoverArray(nums);
    for (auto i: res)
        cout << i << endl;
}