/**
 * Source: t.ly/7D_mQ
 * Date: 2025/1/23
 * Skill:
 * Ref:
 * Runtime: 76 ms, faster than 85.32% of C++ online submissions
 * Memory Usage: 19.20 MB, less than 79.24% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= s.length <= 10 ** 5
 *      1 <= t <= 10 ** 5
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
#define ll long long
const int MOD = 1e9+7;


class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        ll cnt[2][26] = {0};
        for (auto &c: s) {
            cnt[0][c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[(i + 1)%2][(j+1) % 26] = cnt[i%2][j];
            }
            cnt[(i + 1)%2][1] = (cnt[(i + 1)%2][1] + cnt[i%2][25]) % MOD;;
        }

        ll res = 0;
        for (int i = 0; i < 26; i++) {
            res = (res + cnt[t%2][i]) % MOD;
        }
        return res % MOD;
    }
};
