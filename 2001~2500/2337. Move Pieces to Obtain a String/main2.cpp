/**
 * Source: tinyurl.com/ytq9dr4f
 * Date: 2023/10/23
 * Skill:
 * Runtime: 59 ms, faster than 73.05% of C++ online submissions
 * Memory Usage: 19.29 MB, less than 69.92% of C++ online submissions
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
    bool canChange(string start, string target) {
        int idx = 0, sz = start.length();
        for (int i = 0; i < sz; i++) {
            if (target[i] == '_')
                continue;
            while (idx < sz && start[idx] == '_')
                idx++;
            if (idx == sz || start[idx] != target[i])
                return false;
            if (start[idx] == 'L' && idx < i)
                return false;
            if (start[idx] == 'R' && idx > i)
                return false;
            idx++;
        }
        while (idx < sz)
            if (start[idx++] != '_')
                return false;
        return true;
    }
};


int main() {
    Solution s;
    string start = "_L__R__R_";
    string end = "L______RR";
    bool res = s.canChange(start, end);
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