/**
 * Source: ibit.ly/QxwMZ
 * Date: 2025/1/5
 * Skill:
 * Ref:
 * Runtime: 45 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 54.89 MB, less than 15.11% of C++ online submissions
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
    int minLength(string s, int numOps) {
        int hi = s.length(), lo = 1, prev = s[0] - '0', curLen = 1;
        vector<int> nums;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] - '0' == prev) {
                curLen++;
            } else {
                nums.push_back(curLen);
                curLen = 1;
                prev = 1 - prev;
            }
        }
        nums.push_back(curLen);

        if (numOps == 0) {
            return *max_element(nums.begin(), nums.end());
        }

        while (hi > lo) {
            int mid = (lo + hi) / 2;
            bool flag = check(s, numOps, mid, nums);
            if (flag) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
    bool check(string s, int numOps, int len, vector<int>& nums) {
        if (len == 1) {
            int cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < s.length(); i++) {
                char c1 = i % 2 ? '1' : '0';
                char c2 = i % 2 ? '0' : '1';
                cnt1 += s[i] != c1;
                cnt2 += s[i] != c2;
            }
            return min(cnt1, cnt2) <= numOps;
        }
        int cnt = 0;
        for (auto &i: nums) {
            cnt += ceil(1.0 * (i - len) / (len + 1));
        }
        return cnt <= numOps;
    }
};

