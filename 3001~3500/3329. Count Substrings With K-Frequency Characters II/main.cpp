/**
 * Source: is.gd/8Lx4MP
 * Date: 2025/1/22
 * Skill:
 * Ref:
 * Runtime: 133 ms, faster than 44.74% of C++ online submissions
 * Memory Usage: 24.79 MB, less than 55.26% of C++ online submissions
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
#define ll long long


class Solution {
public:
    long long numberOfSubstrings(string s, int k) {
        ll res = 0;
        int cnt[26] = {0}, n = s.length(), r = 0;

        auto check = [&]() {
            for (int i = 0; i < 26; i++) {
                if (cnt[i] >= k) {
                    return true;
                }
            }
            return false;
        };

        for (int l = 0; l < n; l++) {
            while (r < n && !check()) {
                cnt[s[r] - 'a']++;
                r++;
            }
            if (check()) {
                res += n - r + 1;
            }
            cnt[s[l] - 'a']--;
        }
        return res;
    }
};
