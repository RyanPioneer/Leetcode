/**
 * Source: is.gd/txWWp0
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 221 ms, faster than 26.67% of C++ online submissions
 * Memory Usage: 19.60 MB, less than 54.67% of C++ online submissions
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


const int MX = 5e4+10;


class Solution {
public:
    int maxSubstringLength(string s) {
        int len = s.length(), cnt[26] = {0}, presum[MX][26] = {0}, res = 0;
        int left[26], right[26];
        for (int i = 0; i < len; i++) {
            int c = s[i] - 'a';
            cnt[c]++;
            for (int j = 0; j < 26; j++) presum[i + 1][j] = presum[i][j];
            presum[i + 1][c]++;

            left[s[len - 1 - i] - 'a'] = len - 1 - i;
            right[c] = i;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (cnt[i] == 0 || cnt[j] == 0) continue;
                int l = left[i], r = right[j];
                if (l > r || r - l == len - 1) continue;

                bool check = true;
                for (int k = 0; k < 26; k++) {
                    int num = presum[r + 1][k] - presum[l][k];
                    if (num == 0 || num == cnt[k]) continue;
                    check = false;
                    break;
                }
                if (check) res = max(res, r - l + 1);
            }
        }

        return res > 0 ? res : -1;
    }
};