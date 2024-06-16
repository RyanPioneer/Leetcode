/**
 * Source: t.ly/XU_ls
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 453 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 159.21 MB, less than 16.67% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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


class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int, int> mp;
        for (auto &i: meetings) {
            mp[i[0]]++;
            mp[i[1]+1]--;
        }
        int res = 0, cur = 1, num = 0;
        for (auto [d, cnt]: mp) {
            if (d > cur && !num) res += d - cur;
            num += cnt;
            cur = d;
        }
        return res + days - cur + 1;
    }
};