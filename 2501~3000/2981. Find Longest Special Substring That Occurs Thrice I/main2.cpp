/**
 * Source: jpeg.ly/2gyU3
 * Date: 2024/1/6
 * Skill:
 * Ref:
 * Runtime: 828 ms, faster than 27.44% of C++ online submissions
 * Memory Usage: 31.40 MB, less than 98.12% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;
ll mod = 1e9+7;


class Solution {
    int cnt[26], time[26];
public:
    int maximumLength(string s) {
        int lo = 1, hi = s.length() - 2;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check(mid, s)) lo = mid;
            else hi = mid - 1;
        }
        return check(lo, s) ? lo : -1;
    }
    bool check(int len, string &s) {
        fill(cnt, cnt + 26, 0);
        fill(time, time + 26, 0);
        for (int i = 0; i < len; i++) cnt[s[i] - 'a']++;
        int num = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) num++;
        }
        if (num == 1) time[s[0] - 'a']++;
        for (int i = len; i < s.length(); i++) {
            cnt[s[i - len] - 'a']--;
            if (cnt[s[i - len] - 'a'] == 0) num--;
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1) num++;
            if (num == 1) time[s[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) if (time[i] >= 3) return true;
        return false;
    }
};