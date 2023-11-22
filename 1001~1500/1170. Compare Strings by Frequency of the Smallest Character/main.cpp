/**
 * Source: twtr.to/GEO0w
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 97.08% of C++ online submissions
 * Memory Usage: 11.76 MB, less than 95.63% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 2 * 1e3 + 1;


class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int cnt[26] = {0}, num[MX] = {0}, presum[MX] = {0}, total = SZ(words);
        for (auto &w: words) {
            memset(cnt, 0, sizeof cnt);
            char mi = 'z';
            for (auto &c: w) {
                cnt[c - 'a']++;
                mi = min(mi, c);
            }
            num[cnt[mi - 'a']]++;
        }
        for (int i = 1; i < MX; i++) presum[i] = presum[i - 1] + num[i];
        vector<int> res;
        for (auto &q: queries) {
            memset(cnt, 0, sizeof cnt);
            char mi = 'z';
            for (auto &c: q) {
                cnt[c - 'a']++;
                mi = min(mi, c);
            }
            res.push_back(total - presum[cnt[mi - 'a']]);
        }
        return res;
    }
};