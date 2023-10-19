/**
 * Source: tinyurl.com/23n2xahj
 * Date: 2023/10/19
 * Skill:
 * Runtime: 241 ms, faster than 86.48% of C++ online submissions
 * Memory Usage: 18.72 MB, less than 58.61% of C++ online submissions
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
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        unordered_set<int> nums;
        for (auto i: mappings)
            nums.insert(i[0] + i[1] * 128);
        int sz = sub.length();
        for (int i = 0; i <= s.length() - sz; i++) {
            bool flag = true;
            for (int j = 0; j < sz; j++) {
                if (sub[j] == s[i + j])
                    continue;
                if (nums.find(sub[j] + s[i + j] * 128) != nums.end())
                    continue;
                flag = false;
                break;
            }
            if (flag)
                return true;
        }
        return false;
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