/**
 * Source: t.ly/xNzfS
 * Date: 2024/5/30
 * Skill:
 * Ref:
 * Runtime: 77 ms, faster than 8.97% of C++ online submissions
 * Memory Usage: 58.37 MB, less than 12.71% of C++ online submissions
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

const int MX = 1e5+10;


class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int res = 0, n = nums.size();
        int l[MX], r[MX];
        stack<int> a, b;

        for (int i = 0, j = n - 1; i < n; i++, j--) {
            while (!a.empty() && nums[a.top()] < nums[i]) a.pop();
            l[i] = a.empty() ? -1 : a.top();
            a.push(i);
            while (!b.empty() && nums[b.top()] <= nums[j]) b.pop();
            r[j] = b.empty() ? n : b.top();
            b.push(j);
        }

        for (int i = 0; i < n; i++) {
            if (left <= nums[i] && nums[i] <= right) {
                res += (i - l[i]) * (r[i] - i);
            }
        }

        return res;
    }
};