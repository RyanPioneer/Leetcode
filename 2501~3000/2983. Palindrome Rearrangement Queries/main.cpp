/**
 * Source: jpeg.ly/B7h4p
 * Date: 2024/1/7
 * Skill:
 * Ref:
 * Runtime: 976 ms, faster than 49.75% of C++ online submissions
 * Memory Usage: 144.89 MB, less than 84.06% of C++ online submissions
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
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        vector<bool> res;
        int n = s.length(), pre_match[MX] = {0}, prechars[MX][26] = {0}, postchars[MX][26] = {0};
        int cnt1[26], cnt2[26];
        for (int i = 0; i < n / 2; i++) {
            pre_match[i + 1] = pre_match[i] + (s[i] == s[n - 1 - i]);
            for (int j = 0; j < 26; j++) {
                prechars[i + 1][j] = prechars[i][j];
                postchars[i + 1][j] = postchars[i][j];
            }
            prechars[i + 1][s[i] - 'a']++;
            postchars[i + 1][s[n - 1 - i] - 'a']++;
        }
        for (auto &q: queries) {
            int a = q[0], b = q[1], c = n - q[3] - 1, d = n - q[2] - 1;
            int pre = min(a, c) - 1, back = max(b, d) + 1;
            if (pre >= 0 && pre_match[pre + 1] != pre + 1) {
                res.push_back(false);
                continue;
            }
            if (back < n / 2 && pre_match[n / 2] - pre_match[back] != n / 2 - back) {
                res.push_back(false);
                continue;
            }

            bool check = false;
            if (a > d || c > b) {
                int front = min(b, d) + 1, tail = max(a, c) - 1;
                if (tail - front + 1 != pre_match[tail + 1] - pre_match[front]) {
                    res.push_back(false);
                    continue;
                }
                for (int i = 0; i < 26; i++) {
                    if (prechars[b + 1][i] - prechars[a][i] != postchars[b + 1][i] - postchars[a][i]) {
                        check = true;
                        break;
                    }
                    if (prechars[d + 1][i] - prechars[c][i] != postchars[d + 1][i] - postchars[c][i]) {
                        check = true;
                        break;
                    }
                }
            } else {
                for (int i = 0; i < 26; i++) {
                    cnt1[i] = prechars[b + 1][i] - prechars[a][i];
                    cnt2[i] = postchars[d + 1][i] - postchars[c][i];
                    if (a < c) {
                        cnt1[i] -= postchars[c][i] - postchars[a][i];
                        if (cnt1[i] < 0) {
                            check = true;
                            break;
                        }
                    }
                    if (c < a) {
                        cnt2[i] -= prechars[a][i] - prechars[c][i];
                        if (cnt2[i] < 0) {
                            check = true;
                            break;
                        }
                    }
                    if (b > d) {
                        cnt1[i] -= postchars[b + 1][i] - postchars[d + 1][i];
                        if (cnt1[i] < 0) {
                            check = true;
                            break;
                        }
                    }
                    if (d > b) {
                        cnt2[i] -= prechars[d + 1][i] - prechars[b + 1][i];
                        if (cnt2[i] < 0) {
                            check = true;
                            break;
                        }
                    }
                    if (cnt1[i] != cnt2[i]) {
                        check = true;
                        break;
                    }
                }
            }
            if (!check) res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};