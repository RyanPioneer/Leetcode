/**
 * Source: t.ly/ebS2S
 * Date: 2023/9/24
 * Skill:
 * Runtime: 14 ms, faster than 90.00% of C++ online submissions
 * Memory Usage: 26.40 MB, less than 10.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n == maxHeights <= 10 ** 3
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
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll res = 0;
        int sz = maxHeights.size();
        vector<ll> left_sum(sz, 0), right_sum(sz, 0);
        stack<int> left, right;
        for (int i = 0; i < sz; ++i) {
            while (!left.empty() && maxHeights[i] < maxHeights[left.top()])
                left.pop();
            if (left.empty())
                left_sum[i] = (ll)maxHeights[i] * (i + 1);
            else
                left_sum[i] = (ll)maxHeights[i] * (i - left.top()) + left_sum[left.top()];
            left.push(i);
            int j = sz - 1 - i;
            while (!right.empty() && maxHeights[j] < maxHeights[right.top()])
                right.pop();
            if (right.empty())
                right_sum[j] = (ll)maxHeights[j] * (sz - j);
            else
                right_sum[j] = (ll)maxHeights[j] * (right.top() - j) + right_sum[right.top()];
            right.push(j);
        }
        for (int i = 0; i < sz; i++)
            res = max(res, left_sum[i] + right_sum[i] - maxHeights[i]);
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}