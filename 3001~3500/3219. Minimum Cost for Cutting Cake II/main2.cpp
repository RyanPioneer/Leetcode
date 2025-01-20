/**
 * Source: is.gd/j3337u
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 111 ms, faster than 56.96% of C++ online submissions
 * Memory Usage: 233.78 MB, less than 72.15% of C++ online submissions
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


class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ll res = 0;
        int idx1 = 0, idx2 = 0;
        sort(horizontalCut.begin(), horizontalCut.end(), greater<>());
        sort(verticalCut.begin(), verticalCut.end(), greater<>());

        while (idx1 < m-1 || idx2 < n-1) {
            if (idx2 == n-1 || (idx1 < m-1 && horizontalCut[idx1] >= verticalCut[idx2])) {
                res += (ll)horizontalCut[idx1] * (idx2 + 1);
                idx1++;
            } else {
                res += (ll)verticalCut[idx2] * (idx1 + 1);
                idx2++;
            }
        }
        return res;
    }
};
