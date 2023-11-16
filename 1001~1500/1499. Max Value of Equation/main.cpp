/**
 * Source: ibit.ly/hx5WV
 * Date: 2023/11/16
 * Skill:
 * Runtime: 325 ms, faster than 16.29% of C++ online submissions
 * Memory Usage: 109.22 MB, less than 17.26% of C++ online submissions
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


const int MX = 1e5+1;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        multiset<int> nums;
        int pos = 0, res = INT32_MIN, n = points.size();
        for (int i = 0; i < points.size(); i++) {
            if (pos > i) {
                nums.erase(nums.find(points[i][1] + points[i][0]));
            } else {
                pos++;
            }
            while (pos < n && points[pos][0] - points[i][0] <= k) {
                nums.insert(points[pos][0] + points[pos][1]);
                pos++;
            }
            if (!nums.empty()) {
                res = max(res, *nums.rbegin() - points[i][0] + points[i][1]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}