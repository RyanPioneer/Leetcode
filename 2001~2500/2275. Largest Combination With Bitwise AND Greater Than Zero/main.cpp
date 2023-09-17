/**
 * Source: https://rb.gy/8x8fm
 * Date: 2023/9/17
 * Skill:
 * Runtime: 118 ms, faster than 67.62% of C++ online submissions
 * Memory Usage: 57.9 MB, less than 5.37% of C++ online submissions
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
    int largestCombination(vector<int>& candidates) {
        int res = 1;
        for (int i = 0; i < 26; i++) {
            int cnt = 0;
            for (auto j: candidates)
                if ((j & (1 << i)) != 0)
                    cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}