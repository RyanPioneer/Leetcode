/**
 * Source: ibit.ly/1aVs-
 * Date: 2023/10/15
 * Skill:
 * Runtime: 117 ms, faster than 70.00% of C++ online submissions
 * Memory Usage: 80.66 MB, less than 70.00% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> res = {-1, -1};
        int sz = nums.size();
        int prev_min[sz], prev_max[sz];
        prev_min[0] = prev_max[0] = nums[0];
        for (int i = 1; i < sz; i++) {
            prev_max[i] = max(prev_max[i - 1], nums[i]);
            prev_min[i] = min(prev_min[i - 1], nums[i]);
        }
        for (int i = indexDifference; i < sz; i++) {
            if (abs(prev_min[i - indexDifference] - nums[i]) >= valueDifference) {
                res[0] = i;
                for (int j = i - indexDifference; j >= 0; j--)
                    if (nums[j] == prev_min[i - indexDifference]) {
                        res[1] = j;
                        return res;
                    }
            }
            if (abs(prev_max[i - indexDifference] - nums[i]) >= valueDifference) {
                res[0] = i;
                for (int j = i - indexDifference; j >= 0; j--)
                    if (nums[j] == prev_max[i - indexDifference]) {
                        res[1] = j;
                        return res;
                    }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}