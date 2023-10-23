/**
 * Source: tinyurl.com/ytq9dr4f
 * Date: 2023/10/23
 * Skill:
 * Runtime: 58 ms, faster than 76.17% of C++ online submissions
 * Memory Usage: 19.37 MB, less than 57.42% of C++ online submissions
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
        int idx = 0, sz = start.length(), target_dash_num = 0, start_dash_num = 0, right_num = 0;
        for (int i = 0; i < sz; i++) {
            if (target[i] == '_')
                target_dash_num++;
            else if (target[i] == 'L') {
                if (right_num > 0)
                    return false;
                while (idx < sz && start[idx] == '_') {
                    start_dash_num++;
                    idx++;
                }
                if (idx == sz || start[idx] != 'L' || start_dash_num < target_dash_num)
                    return false;
                start_dash_num -= target_dash_num;
                target_dash_num = 0;
                idx++;
            } else {
                while (idx < sz && (start[idx] == '_' || start[idx] == 'R') &&
                       (target_dash_num > start_dash_num || right_num == 0)) {
                    if (start[idx++] == '_')
                        start_dash_num++;
                    else
                        right_num++;
                }
                if (right_num == 0 || target_dash_num > start_dash_num)
                    return false;
                right_num--;
                start_dash_num -= target_dash_num;
                target_dash_num = 0;
                if (right_num == 0 && start_dash_num > 0)
                    return false;
            }
        }
        while (idx < sz) {
            if (start[idx++] != '_')
                return false;
            start_dash_num++;
        }
        return start_dash_num == target_dash_num;
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