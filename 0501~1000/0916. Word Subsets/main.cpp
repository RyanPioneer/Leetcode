/**
 * Source: t.ly/feT8q
 * Date: 2024/6/1
 * Skill:
 * Ref:
 * Runtime: 74 ms, faster than 98.17% of C++ online submissions
 * Memory Usage: 60.96 MB, less than 91.78% of C++ online submissions
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
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int cnt[26] = {0}, cnt2[26];
        for (auto &w: words2) {
            fill(cnt2, cnt2+26, 0);
            for (auto &c: w) cnt2[c-'a']++;
            for (int i = 0; i < 26; i++) {
                cnt[i] = max(cnt[i], cnt2[i]);
            }
        }

        vector<string> res;

        for (auto &w: words1) {
            fill(cnt2, cnt2+26, 0);
            for (auto &c: w) cnt2[c-'a']++;
            bool check = true;
            for (int i = 0; i < 26; i++) {
                if (cnt2[i] < cnt[i]) {
                    check = false;
                    break;
                }
            }
            if (check) res.push_back(w);
        }
        return res;
    }
};