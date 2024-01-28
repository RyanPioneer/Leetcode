/**
 * Source: jpeg.ly/sYrDU
 * Date: 2024/1/27
 * Skill:
 * Ref:
 * Runtime: 65 ms, faster than 95.06% of C++ online submissions
 * Memory Usage: 27.36 MB, less than 28.96% of C++ online submissions
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
    int minimumPushes(string word) {
        vector<int> cnt(24, 0);
        for (auto &c: word) cnt[c - 'a']++;
        sort(cnt.rbegin(), cnt.rend());
        int res = 0;
        for (int i = 0; i < cnt.size(); i++) {
            res += (i + 8) / 8 * cnt[i];
        }
        return res;
    }
};