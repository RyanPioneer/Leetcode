/**
 * Source: jpeg.ly/5p-UG
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime: 312 ms, faster than 40.00% of C++ online submissions
 * Memory Usage: 142.16 MB, less than 40.00% of C++ online submissions
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
    int maximumLength(vector<int>& nums) {
        unordered_map<int, int> cnt, num;
        sort(begin(nums), end(nums));
        int res = 1;
        for (auto &i: nums) {
            if (i == 1) {
                cnt[i]++;
                res = max(res, cnt[i] - (cnt[i] % 2 == 0));
                continue;
            }
            int j = sqrt(i);
            if (j * j == i && cnt[j] >= 2) {
                num[i] = num[j] + 2;
            } else {
                num[i] = 1;
            }
            res = max(res, num[i]);
            cnt[i]++;
        }
        return res;
    }
};