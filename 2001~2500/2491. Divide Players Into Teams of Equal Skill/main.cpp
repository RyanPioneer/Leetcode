/**
 * Source: https://rb.gy/fw8gb
 * Date: 2023/9/12
 * Skill:
 * Runtime: 59 ms, faster than 94.74% of C++ online submissions
 * Memory Usage: 53.04 MB, less than 24.34% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ll total = accumulate(begin(skill), end(skill), 0);
        if (total % (skill.size() / 2) != 0)
            return -1;
        ll res = 0, num = total / (skill.size() / 2), pair = 0;
        unordered_map<int, int> num2count;
        for (auto i: skill) {
            if (num2count[num - i] > 0) {
                res += i * (num - i);
                num2count[num - i]--;
                pair++;
            } else
                num2count[i]++;
        }
        return pair * 2 == skill.size() ? res : -1;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}