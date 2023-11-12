/**
 * Source: t.ly/eWdRe
 * Date: 2023/11/12
 * Skill:
 * Runtime: 55 ms, faster than 10.53% of C++ online submissions
 * Memory Usage: 6.19 MB, less than 94.74% of C++ online submissions
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


class Solution {
public:
    int minimumBoxes(int n) {
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            ll num = 0, cur = mid;
            while (cur > 0) {
                num += cur;
                if (num >= n) break;
                int l = 0, r = cur;
                while (l < r) {
                    ll m = (l + r + 1) / 2;
                    if (m * (m + 1) / 2 <= cur) {
                        l = m;
                    } else {
                        r = m - 1;
                    }
                }
                if (l <= 1) break;
                if (l * (l + 1) / 2 == cur) {
                    cur = (l - 1) * l / 2;
                } else {
                    int next = (l - 1) * l / 2;
                    cur -= l * (l + 1) / 2 + 1;
                    next += cur;
                    cur = next;
                }
            }
            if (num >= n) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{3,4,2,1}, {4,2,3,1},{2,1,0,0},{2,4,0,0}};
    vector<int> nums{2,3,5};
}