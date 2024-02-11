/**
 * Source: is.gd/WfxJu0
 * Date: 2024/2/11
 * Skill:
 * Ref:
 * Runtime: 200 ms, faster than 20.00% of C++ online submissions
 * Memory Usage: 206.05 MB, less than 20.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = SZ(nums), m = SZ(pattern), res = 0;
        vector<int> preprocess(m, 0);

        for (int i = 1; i < m; i++) {
            int len = preprocess[i - 1];
            while (len > 0 && pattern[i] != pattern[len]) len = preprocess[len - 1];
            preprocess[i] = len + (pattern[i] == pattern[len]);
        }

        function<bool(int, int)> check = [&](int idx, int len) {
            if (pattern[len] == -1) {
                return nums[idx] < nums[idx - 1];
            } else if (pattern[len] == 0) {
                return nums[idx] == nums[idx - 1];
            } else {
                return nums[idx] > nums[idx - 1];
            }
        };

        int prev_len = 0;
        for (int i = 1; i < n; ++i) {
            while (prev_len > 0 && !check(i, prev_len)) prev_len = preprocess[prev_len - 1];
            if (check(i, prev_len)) prev_len++;
            if (prev_len == m) {
                res++;
                prev_len = preprocess[m - 1];
            }
        }
        return res;
    }
};