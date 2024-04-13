/**
 * Source: is.gd/MISZkC
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 64 ms, faster than 98.17% of C++ online submissions
 * Memory Usage: 18.97 MB, less than 98.49% of C++ online submissions
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

const int MX = 26;

class Solution {
public:
    string minimizeStringValue(string s) {
        int cnt[MX] = {0}, add[MX] = {0}, num = 0, a;
        for (auto &c: s) {
            if (c == '?') num++;
            else cnt[c - 'a']++;
        }
        while (num--) {
            a = 0;
            for (int i = 1; i < MX; i++) {
                if (cnt[i] < cnt[a]) a = i;
            }
            cnt[a]++;
            add[a]++;
        }

        int idx = 0;
        for (auto &c: s) {
            if (c == '?') {
                while (add[idx] == 0) idx++;
                c = 'a' + idx;
                add[idx]--;
            }
        }
        return s;
    }
};