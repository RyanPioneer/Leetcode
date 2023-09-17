/**
 * Source: https://rb.gy/leo57
 * Date: 2023/9/17
 * Skill:
 * Runtime: 52 ms, faster than 18.18% of C++ online submissions
 * Memory Usage: 55.09 MB, less than 18.18% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0;
        for (int i = 0; i < composition.size(); i++) {
            int lo = 0, hi = INT_MAX / 2;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                ll total = 0;
                for (int j = 0; j < stock.size(); j++) {
                    if ((ll)mid * composition[i][j] > stock[j])
                        total += ((ll)mid * composition[i][j] - stock[j]) * cost[j];
                    if (total > budget)
                        break;
                }
                if (total <= budget)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            res = max(res, lo);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}