/**
 * Source: https://rb.gy/95f0q
 * Date: 2023/9/17
 * Skill:
 * Runtime: 1217 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 436.53 MB, less than 20.00% of C++ online submissions
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
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        int res = 0;
        unordered_map<long long, int> cnt;
        for (auto i: coordinates) {
            int a = i[0], b = i[1];
            for (int j = 0; j <= k; j++) {
                int c = a ^ j, d = b ^ (k - j);
                res += cnt[c * 1e6 + d];
            }
            cnt[a * 1e6 + b]++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}