/**
 * Source: t.ly/GpxtJ
 * Date: 2025/2/2
 * Skill:
 * Ref:
 * Runtime: 41 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 184.01 MB, less than 100.00% of C++ online submissions
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
#define ll long long
const int MOD = 1e9+7;


class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        int sz1 = slots1.size(), sz2 = slots2.size();
        int idx1 = 0, idx2 = 0;

        while (idx1 < sz1 && idx2 < sz2) {
            int start = max(slots1[idx1][0], slots2[idx2][0]);
            int end = min(slots1[idx1][1], slots2[idx2][1]);
            if (end - start >= duration) {
                return {start, start+duration};
            }
            if (slots1[idx1][1] < slots2[idx2][1]) {
                idx1++;
            } else {
                idx2++;
            }
        }
    }
};
