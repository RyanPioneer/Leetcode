/**
 * Source: t.ly/GpxtJ
 * Date: 2025/4/13
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 94.15% of C++ online submissions
 * Memory Usage: 44.40 MB, less than 88.92% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

class Solution {
   public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1,
                                     vector<vector<int>>& slots2,
                                     int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int sz1 = slots1.size(), sz2 = slots2.size();
        int idx1 = 0, idx2 = 0;

        while (idx1 < sz1 && idx2 < sz2) {
            int start = max(slots1[idx1][0], slots2[idx2][0]);
            int end = min(slots1[idx1][1], slots2[idx2][1]);
            if (end - start >= duration) {
                return {start, start + duration};
            }
            if (slots1[idx1][1] < slots2[idx2][1]) {
                idx1++;
            } else {
                idx2++;
            }
        }
        return {};
    }
};
