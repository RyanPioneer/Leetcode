/**
 * Source: t.ly/juBki
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 236 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 95.04 MB, less than 50.00% of C++ online submissions
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
    int minimumDifference(vector<int>& nums, int k) {
        int left = 0, res = INT32_MAX;
        int cnt[32] = {0};
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i], num = 0;
            for (int j = 0; j < 31; j++, a >>= 1) {
                if (a & 1) cnt[j]++;
                if (cnt[j] == i - left + 1) {
                    num += 1 << j;
                }
            }
            res = min(res, abs(num - k));
            while (num < k && left <= i) {
                num = 0;
                a = nums[left];
                for (int j = 0; j < 31; j++, a >>= 1) {
                    if (a & 1) cnt[j]--;
                    if (cnt[j] == i - left) {
                        num += 1 << j;
                    }
                }
                res = min(res, abs(num - k));
                left++;
            }
        }
        return res;
    }
};