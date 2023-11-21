/**
 * Source: twtr.to/GqDGy
 * Date: 2023/11/21
 * Skill:
 * Runtime: 146 ms, faster than 96.51% of C++ online submissions
 * Memory Usage: 84.25 MB, less than 55.62% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
#define ll long long
using namespace std;
const int MX = 40;
ll mod = 1e9+7;


class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        ll res = 0;
        for (int i = 0; i < SZ(nums); i++) {
            int j = nums[i] - i;
            res += i - mp[j];
            mp[j]++;
        }
        return res;
    }
};