/**
 * Source: is.gd/ML6SoL
 * Date: 2024/2/11
 * Skill:
 * Ref:
 * Runtime: 32 ms, faster than 75.00% of C++ online submissions
 * Memory Usage: 27.66 MB, less than 37.50% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define ll long long
typedef unsigned long long ULL;

const int MX = 26;


class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = SZ(words), m = SZ(words[0]), cnt[MX] = {0};
        int odd_char = 0, infeasible = 0;
        for (auto &w: words) {
            if (w.length() % 2) odd_char--;
            for (auto &c: w) {
                cnt[c - 'a']++;
            }
        }
        for (int i = 0; i < MX; i++) {
            odd_char += cnt[i] % 2;
        }
        sort(begin(words), end(words), [](const string &a, const string &b) {
            return a.length() > b.length();
        });
        for (auto &word : words) {
            if (odd_char <= 0) break;
            infeasible++;
            odd_char -= word.length() - (word.length() % 2);
        }
        return n - infeasible;
    }
};