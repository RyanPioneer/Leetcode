/**
 * Source: https://rb.gy/bvnqd
 * Date: 2023/9/14
 * Skill: https://rb.gy/y5vp8
 * Runtime: 5 ms, faster than 93.21% of C++ online submissions
 * Memory Usage: 7.16 MB, less than 95.71% of C++ online submissions
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
    string crackSafe(int n, int k) {
        string res(n - 1, '0');
        unordered_map<string, int>str2num;
        for (int i = 0; i < pow(k, n); i++) {
            string ss = res.substr(res.size() - (n - 1), n - 1);
            str2num[ss] = (str2num[ss] + 1) % k;
            res += '0' + str2num[ss];
        }
        return res;
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
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}