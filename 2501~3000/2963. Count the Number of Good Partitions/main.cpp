/**
 * Source: jpeg.ly/7QvB6
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 223 ms, faster than 800.00% of C++ online submissions
 * Memory Usage: 134.69 MB, less than 60.00% of C++ online submissions
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
ll mod = 1e9+7;


ll quick_pow(ll x, ll n, ll m) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % m;
        x = x * x % m;
    }
    return res;
}

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> right;
        for (int i = 0; i < nums.size(); i++) {
            right[nums[i]] = i;
        }
        int num = 0, cur_right = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_right = max(cur_right, right[nums[i]]);
            if (cur_right == i) num++;
        }
        return quick_pow(2, num - 1, mod);
    }
};