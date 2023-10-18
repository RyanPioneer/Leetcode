/**
 * Source: twtr.to/LWUpK
 * Date: 2023/10/18
 * Skill:
 * Runtime: 127 ms, faster than 97.84% of C++ online submissions
 * Memory Usage: 83.31 MB, less than 91.87% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int visited[100001] = {0}, res = 1;
        for (auto i: nums) {
            visited[i] = 1 + ((long long)i * i > 100000 ? 0 : visited[i * i]);
            res = max(res, visited[i]);
        }
        return res > 1 ? res : -1;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}