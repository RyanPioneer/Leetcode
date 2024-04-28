/**
 * Source: tinyurl.com/2anr95m8
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 1389 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 302.29 MB, less than 50.00% of C++ online submissions
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
    int medianOfUniquenessArray(vector<int>& nums) {
        int left = 1, right = nums.size(), len = nums.size();
        ll total = (ll)len * (len + 1) / 2;
        unordered_map<int, int> mp;

        while (left < right) {
            int mid = (left + right) / 2, l = 0, cnt = 0;
            ll num = 0;
            mp.clear();
            for (int r = 0; r < len; r++) {
                mp[nums[r]]++;
                if (mp[nums[r]] == 1) cnt++;
                while (cnt > mid) {
                    mp[nums[l++]]--;
                    if (mp[nums[l - 1]] == 0) {
                        cnt--;
                    }
                }
                num += r - l + 1;
            }
            if (num >= (total + 1) / 2) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};