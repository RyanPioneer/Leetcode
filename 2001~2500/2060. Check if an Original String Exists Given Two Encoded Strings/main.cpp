/**
 * Source: jpeg.ly/oPA65
 * Date: 2023/12/22
 * Skill:
 * Ref:
 * Runtime: 840 ms, faster than 11.24% of C++ online submissions
 * Memory Usage: 194.49 MB, less than 20.12% of C++ online submissions
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
    unordered_set<ll> visited;
    int sz1, sz2;
public:
    bool possiblyEquals(string s1, string s2) {
        sz1 = s1.length(), sz2 = s2.length();
        return dfs(s1, 0, 0, s2, 0, 0);
    }
    bool dfs(string &s1, int idx1, int num1, string &s2, int idx2, int num2) {
        ll hash = idx1 * 1e9 + num1 * 1e6 + idx2 * 1e3 + num2;
        if (visited.find(hash) != visited.end()) return false;
        if (idx1 == sz1 && idx2 == sz2) return num1 == num2;
        if (idx1 < sz1 && isdigit(s1[idx1])) {
            int s = idx1;
            while (idx1 < sz1 && isdigit(s1[idx1])) idx1++;
            unordered_set<int> nums = getNum(s1.substr(s, idx1 - s));
            for (auto i: nums) {
                if (dfs(s1, idx1, num1 + i, s2, idx2, num2)) {
                    return true;
                }
            }
        } else if (idx2 < sz2 && isdigit(s2[idx2])) {
            int s = idx2;
            while (idx2 < sz2 && isdigit(s2[idx2])) idx2++;
            unordered_set<int> nums = getNum(s2.substr(s, idx2 - s));
            for (auto i: nums) {
                if (dfs(s1, idx1, num1, s2, idx2, num2 + i)) {
                    return true;
                }
            }
        }else if (idx1 == sz1) {
            if (num1 <= num2) return false;
            num1 -= num2;
            if (dfs(s1, idx1, num1 - 1, s2, idx2 + 1, 0)) return true;
        } else if (idx2 == sz2) {
            if (num2 <= num1) return false;
            num2 -= num1;
            if (dfs(s1, idx1 + 1, 0, s2, idx2, num2 - 1)) return true;
        } else if (num1 > 0 && num2 > 0) {
            int mi = min(num1, num2);
            if (dfs(s1, idx1, num1 - mi, s2, idx2, num2 - mi)) return true;
        } else if (num1 > 0) {
            if (dfs(s1, idx1, num1 - 1, s2, idx2 + 1, 0)) return true;
        } else if (num2 > 0) {
            if (dfs(s1, idx1 + 1, num1, s2, idx2, num2 - 1)) return true;
        } else {
            if (s1[idx1] == s2[idx2] && dfs(s1, idx1 + 1, 0, s2, idx2 + 1, num2)) {
                return true;
            }
        }
        visited.insert(hash);
        return false;
    }
    unordered_set<int> getNum(string s) {
        unordered_set<int> res;
        res.insert(stoi(s));
        int len = s.length();
        if (len == 2) {
            int d1 = s[0] - '0', d2 = s[1] - '0';
            res.insert(d1 + d2);
        } else if (len == 3) {
            int d1 = s[0] - '0', d2 = s[1] - '0', d3 = s[2] - '0';
            res.insert(d1 + d2 + d3);
            res.insert(d1 * 10 + d2 + d3);
            res.insert(d1 + d2 * 10 + d3);
        }
        return res;
    }
};