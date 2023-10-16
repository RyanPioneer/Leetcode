/**
 * Source: twtr.to/HFyOW
 * Date: 2023/10/16
 * Skill:
 * Runtime: 903 ms, faster than 8.41% of C++ online submissions
 * Memory Usage: 33.02 MB, less than 76.19% of C++ online submissions
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
#include <functional>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        function<int(int, int)> dfs;
        dfs = [&](int idx, int state) {
            if (idx == sz)
                return 1;
            bool flag = true;
            for (int i = 0; i < idx; i++)
                if (((state >> i) & 1) != 0 && nums[idx] - nums[i] == k) {
                    flag = false;
                    break;
                }
            int cnt = dfs(idx + 1, state);
            if (flag)
                cnt += dfs(idx + 1, state + (1 << idx));
            return cnt;
        };
        return dfs(0, 0) - 1;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}