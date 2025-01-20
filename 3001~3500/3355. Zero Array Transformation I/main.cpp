/**
 * Source: jpeg.ly/0H3A6
 * Date: 2025/1/18
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 90.64% of C++ online submissions
 * Memory Usage: 290.51 MB, less than 98.13% of C++ online submissions
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
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int diff[MX] = {0};
        for (auto& q: queries) {
            diff[q[0]]++;
            diff[q[1]+1]--;
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
