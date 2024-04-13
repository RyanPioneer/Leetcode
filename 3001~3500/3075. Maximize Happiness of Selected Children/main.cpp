/**
 * Source: is.gd/5AX53T
 * Date: 2024/3/10
 * Skill:
 * Ref:
 * Runtime: 156 ms, faster than 74.20% of C++ online submissions
 * Memory Usage: 107.13 MB, less than 60.53% of C++ online submissions
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
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ll res = 0;
        sort(begin(happiness), end(happiness), greater<int>());
        for (int i = 0; i < k && happiness[i] > i; i++) {
            res += happiness[i] - i;
        }
        return res;
    }
};