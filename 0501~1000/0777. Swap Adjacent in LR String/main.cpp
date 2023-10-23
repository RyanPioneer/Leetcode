/**
 * Source: tinyurl.com/y2syu722
 * Date: 2023/10/23
 * Skill:
 * Runtime: 4 ms, faster than 87.71% of C++ online submissions
 * Memory Usage: 7.70 MB, less than 66.34% of C++ online submissions
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
    bool canTransform(string str, string target) {
        int idx = 0, sz = str.length();
        for (int i = 0; i < sz; i++) {
            if (target[i] == 'X')
                continue;
            while (idx < sz && str[idx] == 'X')
                idx++;
            if (idx == sz || str[idx] != target[i])
                return false;
            if (str[idx] == 'L' && idx < i)
                return false;
            if (str[idx] == 'R' && idx > i)
                return false;
            idx++;
        }
        while (idx < sz)
            if (str[idx++] != 'X')
                return false;
        return true;
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