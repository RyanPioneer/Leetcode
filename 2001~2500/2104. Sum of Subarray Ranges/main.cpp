/**
 * Source: https://rb.gy/354dc
 * Date: 2023/9/19
 * Skill:
 * Runtime: 11 ms, faster than 93.01% of C++ online submissions
 * Memory Usage: 11.87 MB, less than 12.16% of C++ online submissions
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
    long long subArrayRanges(vector<int>& nums) {
        ll res = 0;
        int sz = nums.size();
        vector<int> prev_smaller(sz, -1), next_smaller(sz, sz), prev_bigger(sz, -1), next_bigger(sz, sz);
        stack<int> smaller_stack, bigger_stack;
        for (int i = 0; i < sz; i++) {
            while (!smaller_stack.empty() && nums[smaller_stack.top()] > nums[i])
                smaller_stack.pop();
            if (!smaller_stack.empty())
                prev_smaller[i] = smaller_stack.top();
            smaller_stack.push(i);
            while (!bigger_stack.empty() && nums[bigger_stack.top()] < nums[i])
                bigger_stack.pop();
            if (!bigger_stack.empty())
                prev_bigger[i] = bigger_stack.top();
            bigger_stack.push(i);
        }
        while (!smaller_stack.empty())
            smaller_stack.pop();
        while (!bigger_stack.empty())
            bigger_stack.pop();
        for (int i = sz - 1; i >= 0; i--) {
            while (!smaller_stack.empty() && nums[smaller_stack.top()] >= nums[i])
                smaller_stack.pop();
            if (!smaller_stack.empty())
                next_smaller[i] = smaller_stack.top();
            smaller_stack.push(i);
            while (!bigger_stack.empty() && nums[bigger_stack.top()] <= nums[i])
                bigger_stack.pop();
            if (!bigger_stack.empty())
                next_bigger[i] = bigger_stack.top();
            bigger_stack.push(i);
        }
        for (int i = 0; i < sz; i++) {
            res += (ll)nums[i] * (i - prev_bigger[i]) * (next_bigger[i] - i);
            res -= (ll)nums[i] * (i - prev_smaller[i]) * (next_smaller[i] - i);
        }
        return res;
    }
};

int main() {

}