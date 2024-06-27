/**
 * Source: t.ly/8uaie
 * Date: 2024/6/26
 * Skill:
 * Ref:
 * Runtime: 1037 ms, faster than 69.30% of C++ online submissions
 * Memory Usage: 179.06 MB, less than 59.23% of C++ online submissions
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
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> nums;
        for (auto &i: nums1) {
            if (i % k == 0) {
                nums.push_back(i / k);
            }
        }

        unordered_map<int, int> mp;
        for (auto &i: nums2) {
            mp[i]++;
        }

        ll res = 0;
        for (auto &i: nums) {
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    res += mp[j];
                }
                if (i % j == 0 && j != i / j) {
                    res += mp[i/j];
                }
            }
        }
        return res;
    }
};