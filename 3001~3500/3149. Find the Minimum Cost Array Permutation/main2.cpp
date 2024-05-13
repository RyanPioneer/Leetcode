/**
 * Source: ibit.ly/Hgy-p
 * Date: 2024/5/13
 * Skill:
 * Ref:
 * Runtime: 220 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 124.70 MB, less than 100.00% of C++ online submissions
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
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(1 << n, vector<int>(n, INT32_MAX));
        vector<vector<int>> nextNum(1 << n, vector<int>(n, -1));

        for (int i = 1; i < n; i++) {
            memo[(1 << n) - 1][i] = abs(i - nums[0]);
        }
        for (int state = (1 << n) - 3; state > 0; state -= 2) {
            for (int i = 0; i < n; i++) {
                if ((state >> i & 1) == 0) {
                    continue;
                }
                for (int k = 1; k < n; k++) {
                    if ((state >> k & 1) != 0) {
                        continue;
                    }
                    int num = memo[state | 1 << k][k] + abs(i - nums[k]);
                    if (num < memo[state][i]) {
                        memo[state][i] = num;
                        nextNum[state][i] = k;
                    }
                }
            }
        }

        vector<int> res;
        int state = 0, num = 0;
        while (num >= 0) {
            res.push_back(num);
            state |= 1 << num;
            num = nextNum[state][num];
        }
        return res;
    }
};