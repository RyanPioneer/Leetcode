/**
 * Source: tinyurl.com/ylrtna3a
 * Date: 2023/10/23
 * Skill:
 * Runtime: 31 ms, faster than 77.83% of C++ online submissions
 * Memory Usage: 32.26 MB, less than 93.91% of C++ online submissions
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
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int score[26], res = 0, cur_num = 0;
        for (int i = 0; i < 26; i++)
            score[i] = 2000;
        for (int i = 0; i < vals.size(); i++)
            score[chars[i] - 'a'] = vals[i];
        for (auto c: s) {
            int num = (score[c - 'a'] != 2000 ? score[c - 'a'] : c - 'a' + 1);
            cur_num = max(num, cur_num + num);
            res = max(res, cur_num);
        }
        return res;
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