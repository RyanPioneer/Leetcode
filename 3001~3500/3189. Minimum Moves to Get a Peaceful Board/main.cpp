/**
 * Source: ibit.ly/TvZY0
 * Date: 2024/6/21
 * Skill: The relative orders for rows and columns are unchanged.
 * Ref:
 * Runtime: 38 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 41.57 MB, less than 100.00% of C++ online submissions
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


class Solution {
public:
    int minMoves(vector<vector<int>>& rooks) {
        int n = rooks.size(), res = 0;

        function<void(vector<int>)> cal = [&](vector<int> arr) {
            sort(begin(arr), end(arr));
            for (int i = 0; i < n; i++) {
                res += abs(i - arr[i]);
            }
        };

        for (int i = 0; i < 2; i++) {
            vector<int> nums;
            for (auto &j: rooks) {
                nums.push_back(j[i]);
            }
            cal(nums);
        }
        return res;
    }
};