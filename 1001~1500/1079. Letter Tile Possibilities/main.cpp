/**
 * Source: is.gd/RulVCX
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 93.49% of C++ online submissions
 * Memory Usage: 6.40 MB, less than 82.46% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= tiles.length <= 7
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
    int res = 0, cnt[26] = {0}, len;
public:
    int numTilePossibilities(string tiles) {
        for (auto &c: tiles) cnt[c - 'A']++;
        len = tiles.length();
        dfs(0);
        return res;
    }
    void dfs(int idx) {
        if (idx == len) return;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                res++;
                cnt[i]--;
                dfs(idx + 1);
                cnt[i]++;
            }
        }
    }
};