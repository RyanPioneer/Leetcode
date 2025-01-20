/**
 * Source: jpeg.ly/9kHtu
 * Date: 2025/1/18
 * Skill:
 * Ref:
 * Runtime: 79 ms, faster than 40.02% of C++ online submissions
 * Memory Usage: 321.56 MB, less than 95.17% of C++ online submissions
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
const int MX = 1e5+10;


class Solution {
    int diff[MX] = {0};
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int lo = 0, hi = queries.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (checkFeasible(mid, nums, queries)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        if (checkFeasible(lo, nums, queries)) {
            return lo;
        }
        return -1;
    }
    bool checkFeasible(int idx, vector<int>& nums, vector<vector<int>>& queries) {
        memset(diff, 0, sizeof(diff));
        for (int i = 0; i < idx; i++) {
            diff[queries[i][0]] += queries[i][2];
            diff[queries[i][1]+1] -= queries[i][2];
        }
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (cnt < nums[i]) {
                return false;
            }
        }
        return true;
    }
};
