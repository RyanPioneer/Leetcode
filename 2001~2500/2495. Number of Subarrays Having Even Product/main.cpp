/**
 * Source: ibit.ly/AI357
 * Date: 2024/6/26
 * Skill:
 * Ref:
 * Runtime: 72 ms, faster than 70.00% of C++ online submissions
 * Memory Usage: 69.22 MB, less than 10.00% of C++ online submissions
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
    long long evenProduct(vector<int>& nums) {
        ll res = 0;
        int n = nums.size(), left = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                res += (ll)(i - left) * (n - i);
                left = i;
            }
        }
        return res;
    }
};