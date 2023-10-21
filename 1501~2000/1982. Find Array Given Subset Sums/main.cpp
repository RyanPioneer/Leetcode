/**
 * Source: tinyurl.com/yta5m56e
 * Date: 2023/10/21
 * Skill:
 * Runtime: 1662 ms, faster than 6.35% of C++ online submissions
 * Memory Usage: 418.82 MB, less than 6.35% of C++ online submissions
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
#include <list>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> res;
        function<bool(vector<int>, int)> dfs;
        dfs = [&](vector<int> nums, int m) {
            if (m == 1) {
                if (nums[0] == 0 || nums[1] == 0) {
                    res.push_back(nums[0] != 0 ? nums[0] : nums[1]);
                    return true;
                } else
                    return false;
            }
            int sz = nums.size();
            nth_element(begin(nums), begin(nums) + sz - 1, end(nums));
            nth_element(begin(nums), begin(nums) + sz - 2, end(nums));
            vector<int> nums1;
            multiset<int> set1(begin(nums), end(nums));
            int num1 = nums[sz - 1] - nums[sz - 2];
            for (int i = 0; i < sz / 2; i++) {
                int num = *set1.rbegin();
                if (set1.find(num - num1) == set1.end())
                    break;
                nums1.push_back(num - num1);
                set1.erase(set1.lower_bound(num));
                set1.erase(set1.lower_bound(num - num1));
            }
            if (nums1.size() == sz / 2) {
                res.push_back(num1);
                if (dfs(nums1, m - 1))
                    return true;
                res.pop_back();
            }

            nums1.clear();
            multiset<int> set2(begin(nums), end(nums));
            int num2 = nums[sz - 2] - nums[sz - 1];
            for (int i = 0; i < sz / 2; i++) {
                int num = *set2.begin();
                if (set2.find(num - num2) == set2.end())
                    break;
                nums1.push_back(num - num2);
                set2.erase(set2.lower_bound(num));
                set2.erase(set2.lower_bound(num - num2));
            }
            if (nums1.size() == sz / 2) {
                res.push_back(num2);
                if (dfs(nums1, m - 1))
                    return true;
                res.pop_back();
            }
            return false;
        };
        dfs(sums, n);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{89135};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}