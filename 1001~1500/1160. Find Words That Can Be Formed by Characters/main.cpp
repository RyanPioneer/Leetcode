/**
 * Source: jpeg.ly/UeINj
 * Date: 2023/12/2
 * Skill:
 * Ref:
 * Runtime: 36 ms, faster than 93.72% of C++ online submissions
 * Memory Usage: 15.88 MB, less than 87.44% of C++ online submissions
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
    int countCharacters(vector<string>& words, string chars) {
        int cnt[MX] = {0}, res = 0, num[MX];
        for (auto &c: chars) cnt[c - 'a']++;
        for (auto &w: words) {
            fill(num, num + MX, 0);
            bool check = true;
            for (auto &c: w) {
                num[c - 'a']++;
                if (num[c - 'a'] > cnt[c - 'a']) {
                    check = false;
                    break;
                }
            }
            if (check) res += w.length();
        }
        return res;
    }
};