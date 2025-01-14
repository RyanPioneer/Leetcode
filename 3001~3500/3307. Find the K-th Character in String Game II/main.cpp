/**
 * Source: ibit.ly/EwCqu
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 291 ms, faster than 46.62% of C++ online submissions
 * Memory Usage: 57.12 MB, less than 38.79% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= k <= 10 ** 14
 *      1 <= operations.length <= 100
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
    char kthCharacter(long long k, vector<int>& operations) {
        auto f = [&](char c) {
            if (c == '0') return "01";
            return "10";
        };
    }
};
