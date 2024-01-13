/**
 * Source: jpeg.ly/rE2qk
 * Date: 2024/1/12
 * Skill:
 * Ref:
 * Runtime: 98 ms, faster than 98.12% of C++ online submissions
 * Memory Usage: 88.94 MB, less than 38.75% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;
ll mod = 1e9+7;
typedef pair<int, int> PII;


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int num = 0, res = 0;
        for (auto &i: nums) k ^= i;
        return __builtin_popcount(k);
    }
};