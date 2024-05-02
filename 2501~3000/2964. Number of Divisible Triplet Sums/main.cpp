/**
 * Source: tinyurl.com/28j9qdr2
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 81 ms, faster than 61.29% of C++ online submissions
 * Memory Usage: 29.99 MB, less than 70.97% of C++ online submissions
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
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> mp;
        int res = 0, n = nums.size();

        for (int i = 1; i < n; i++) mp[nums[i] % d]++;
        for (int i = 1; i + 1 < n; i++) {
            mp[nums[i] % d]--;
            for (int j = i - 1; j >= 0; j--) {
                int k = (nums[i] % d + nums[j] % d) % d;
                k = (d - k) % d;
                res += mp[k];
            }
        }
        return res;
    }
};