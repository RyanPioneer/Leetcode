/**
 * Source: t.ly/ebS2S
 * Date: 2023/9/24
 * Skill:
 * Runtime: 49 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 24.04 MB, less than 10.00% of C++ online submissions
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
        for (int i = 0; i < maxHeights.size(); i++) {
            ll num = maxHeights[i];
            int left = maxHeights[i], right = maxHeights[i];
            for (int j = i - 1; j >= 0; j--) {
                left = min(left, maxHeights[j]);
                num += left;
            }
            for (int j = i + 1; j < maxHeights.size(); j++) {
                right = min(right, maxHeights[j]);
                num += right;
            }
            res = max(num, res);
        }
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