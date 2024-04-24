/**
 * Source: t.ly/yvWlz
 * Date: 2024/4/24
 * Skill:
 * Ref:
 * Runtime: 130 ms, faster than 97.94% of C++ online submissions
 * Memory Usage: 43.16 MB, less than 59.79% of C++ online submissions
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


const int MX = 26;


class Solution {
public:
    string makeAntiPalindrome(string s) {
        int len = s.length(), cnt[MX] = {0};

        for (auto &c: s) cnt[c - 'a']++;
        for (int i = 0; i < MX; i++) {
            if (cnt[i] > len / 2) {
                return "-1";
            }
        }

        string res(len, 'a');
        int pos = 0, p2 = -1, p3 = -1;

        for (char i = 'a'; i <= 'z'; i++) {
            while (pos < p2 && cnt[i - 'a']) {
                res[pos] = i;
                pos++;
                cnt[i - 'a']--;
            }
            if (cnt[i - 'a'] == 0) continue;
            if (pos == p2) pos = p3;
            if (pos >= len / 2 || pos + cnt[i - 'a'] <= len / 2) {
                for (int j = 0; j < cnt[i - 'a']; j++) {
                    res[pos++] = i;
                }
            } else {
                int l = len / 2 - pos;
                while (pos < len / 2) {
                    res[pos++] = i;
                    cnt[i - 'a']--;
                }
                p2 = p3 = len / 2 + l;
                while (cnt[i - 'a']) {
                    res[p3++] = i;
                    cnt[i - 'a']--;
                }
            }
        }
        return res;
    }
};