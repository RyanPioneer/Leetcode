/**
 * Source: tinyurl.com/yrp5uzk4
 * Date: 2023/10/26
 * Skill:
 * Runtime: 169 ms, faster than 38.08% of C++ online submissions
 * Memory Usage: 121.17 MB, less than 73.22% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
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
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (auto i: nums) {
            while (!res.empty() && gcd(i, res.back()) != 1) {
                i = lcm(i, res.back());
                res.pop_back();
            }
            res.push_back(i);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
}