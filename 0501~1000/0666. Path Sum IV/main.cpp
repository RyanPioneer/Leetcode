/**
 * Source: ibit.ly/4V3ou
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 12.69 MB, less than 6.99% of C++ online submissions
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
typedef pair<int, int> PII;
#define MK make_pair


class Solution {
public:
    int pathSum(vector<int>& nums) {
        int res = 0;
        int num[6][(1 << 5) + 1], notLeave[6][(1 << 5) + 1] = {0};
        num[1][0] = nums[0] % 10;
        for (int i = 1; i < nums.size(); i++) {
            int d = nums[i] / 100;
            int p = nums[i] % 100 / 10 - 1;
            int v = nums[i] % 10;
            num[d][p] = v;
            notLeave[d - 1][p / 2] = 1;
        }
        queue<PII> q;
        for (int i = 0; i < nums.size(); i++) {
            int d = nums[i] / 100;
            int p = nums[i] % 100 / 10 - 1;
            int v = nums[i] % 10;
            if (!notLeave[d][p]) {
                q.push(MK(d, p));
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            res += num[x][y];
            if (x != 1) {
                q.push(MK(x - 1, y / 2));
            }
        }
        return res;
    }
};