/**
 * Source: t.ly/K49d7
 * Date: 2023/9/23
 * Skill:
 * Runtime: 132 ms, faster than 65.39% of C++ online submissions
 * Memory Usage: 98.70 MB, less than 13.48% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums1.length, nums2.length <= 10 ** 5
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
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0, pos = nums1.size() - 1, sz1 = nums1.size();
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (pos >= 0 && nums1[pos] <= nums2[i])
                pos--;
            if (pos < sz1 - 1 && i > pos)
                res = max(res, i - pos - 1);
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