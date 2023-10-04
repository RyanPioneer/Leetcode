/**
 * Source: ibit.ly/UKf-r
 * Date: 2023/10/4
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.68 MB, less than 10.74% of C++ online submissions
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
    vector<int> height;
    int res = INT32_MAX;
public:
    int tilingRectangle(int m, int n) {
        height.resize(min(m, n));
        res = m * n;
        dfs(0, min(m, n), max(m, n));
        return res;
    }
    void dfs(int cur, int m, int n) {
        if (cur >= res)
            return;
        int s = min_element(begin(height), end(height)) - begin(height);
        if (height[s] == n) {
            res = cur;
            return;
        }
        int e = s, h = height[s];
        while (e + 1 < m && height[e + 1] == h && h + (e + 2 - s) <= n) e++;
        for (int i = e; i >= s; i--) {
            int hh = i - s + 1;
            for (int j = s; j <= i; j++)
                height[j] += hh;
            dfs(cur + 1, m, n);
            for (int j = s; j <= i; j++)
                height[j] -= hh;
        }
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}