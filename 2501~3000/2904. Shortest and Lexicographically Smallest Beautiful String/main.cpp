/**
 * Source: twtr.to/RJNw8
 * Date: 2023/10/15
 * Skill:
 * Runtime: 2 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.62 MB, less than 100.00% of C++ online submissions
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
    string shortestBeautifulSubstring(string s, int k) {
        string res;
        int cnt = 0, left = 0, min_len = INT32_MAX;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                cnt++;
                if (cnt == k) {
                    while (s[left] != '1')
                        left++;
                    if (i - left + 1 < min_len) {
                        res = s.substr(left, i - left + 1);
                        min_len = i - left + 1;
                    } else if (i - left + 1 == min_len && s.substr(left, i - left + 1) < res)
                        res = s.substr(left, i - left + 1);
                    left++;
                    cnt--;
                }
            }
        }
        return res;
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
    string ss = "001110101101101111";
    string res = s.shortestBeautifulSubstring(ss, 10);
}