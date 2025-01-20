/**
 * Source: jpeg.ly/wbzrf
 * Date: 2025/1/18
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 78.79% of C++ online submissions
 * Memory Usage: 85.98 MB, less than 91.41% of C++ online submissions
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


#define ll long long
using namespace std;
const int MX = 2e5+1;


class Solution {
    int diff[MX] = {0};
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        for (int i = 0; i < n / 2; i++) {
            int mi = min(nums[i], nums[n - i - 1]);
            int ma = max(nums[i], nums[n - i - 1]);
            diff[2] += 2;
            diff[mi + 1] -= 1;
            diff[mi + ma] -= 1;
            diff[mi + ma + 1] += 1;
            diff[ma + limit + 1] += 1;
        }

        int cnt = 0, res = 2 * n;
        for (int i = 2; i < 2 * limit + 1; i++) {
            cnt += diff[i];
            res = min(res, cnt);
        }
        return res;
    }
};
