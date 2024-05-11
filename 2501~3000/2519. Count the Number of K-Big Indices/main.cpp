/**
 * Source: t.ly/bURvu
 * Date: 2024/5/7
 * Skill:
 * Ref:
 * Runtime: 72 ms, faster than 68.09% of C++ online submissions
 * Memory Usage: 113.34 MB, less than 5.67% of C++ online submissions
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
const int MX = 1e5+7;

class BIT {
public:
    ll arr[MX] = {0};

    void update(int idx, ll num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    ll query_sum(int idx) {
        ll num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};

class Solution {
public:
    int kBigIndices(vector<int>& nums, int k) {
        int n = nums.size();
        BIT *prev = new BIT(), *after = new BIT();
        for (auto &i: nums) {
            after->update(i, 1);
        }
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            after->update(nums[i], -1);
            int num1 = prev->query_sum(nums[i] - 1);
            int num2 = after->query_sum(nums[i] - 1);
            if (num1 >= k && num2 >= k) res++;
            prev->update(nums[i], 1);
        }
        return res;
    }
};