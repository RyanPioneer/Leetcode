/**
 * Source: tinyurl.com/ypdrghxv
 * Date: 2023/10/25
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.32 MB, less than 28.86% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int kthGrammar(int n, int k) {
        function<int(int, int)> helper;
        helper = [&](int x, int y) {
            if (x == 1) return 0;
            int num = helper(x - 1, y / 2);
            return y % 2 == 0 ? num : 1 - num;
        };
        return helper(n, k - 1);
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3}, nums2{5,4,6,2,1,3};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}