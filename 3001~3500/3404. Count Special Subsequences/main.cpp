/**
 * Source: ibit.ly/Re3te
 * Date: 2025/1/12
 * Skill:
 * Ref:
 * Runtime: 1328 ms, faster than 26.01% of C++ online submissions
 * Memory Usage: 202.94 MB, less than 15.68% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      7 <= nums.length <= 1000
 *      1 <= nums[i] <= 1000
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <cmath>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;

#define ll long long


class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int sz = nums.size();
        ll res = 0;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < sz; i++) {
            for (int j = i + 2; j < sz; j++) {
                mp[getKey(nums[i], nums[j])].push_back(i);
            }
        }
        for (auto &i: mp) {
            sort(i.second.begin(), i.second.end());
        }
        for (int i = 0; i < sz; i++) {
            for (int j = i + 2; j < sz; j++) {
                int key = getKey(nums[j], nums[i]);
                auto it = lower_bound(mp[key].begin(), mp[key].end(), j + 2);
                res += mp[key].end() - it;
            }
        }
        return res;
    }
    int getKey(int x, int y) {
        int g = gcd(x,y);
        return x / g * 1000 + y / g;
    }
};
