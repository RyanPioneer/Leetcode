/**
 * Source: tinyurl.com/yvkvv4lh
 * Date: 2023/10/23
 * Skill:
 * Runtime: 217 ms, faster than 68.21% of C++ online submissions
 * Memory Usage: 259.83 MB, less than 57.55% of C++ online submissions
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
    bool doesValidArrayExist(vector<int>& derived) {
        function<bool(int)> check;
        check = [&](int num) {
            int a = num;
            for (int i = 0; i < derived.size(); i++)
                a ^= derived[i];
            return a == num;
        };
        return check(0) || check(1);
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}