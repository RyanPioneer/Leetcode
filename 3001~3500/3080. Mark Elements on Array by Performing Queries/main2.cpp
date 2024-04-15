/**
 * Source: is.gd/TylZ69
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 267 ms, faster than 70.42% of C++ online submissions
 * Memory Usage: 133.76 MB, less than 77.69% of C++ online submissions
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
#define ll long long


class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        ll total = accumulate(begin(nums), end(nums), 0ll);
        vector<int> idx(n);

        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](const int a, const int b) {
            if (nums[a] == nums[b]) return a < b;
            else return nums[a] < nums[b];
        });

        vector<ll> res;
        int curIdx = 0;

        for (auto &q: queries) {
            total -= nums[q[0]];
            nums[q[0]] = 0;
            while (q[1] > 0 && curIdx < n) {
                if (nums[idx[curIdx++]] > 0) {
                    total -= nums[idx[curIdx - 1]];
                    nums[idx[curIdx - 1]] = 0;
                    q[1]--;
                }
            }
            res.push_back(total);
        }
        return res;
    }
};