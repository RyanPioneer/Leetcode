/**
 * Source: jpeg.ly/JFpHb
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 681 ms, faster than 31.78% of C++ online submissions
 * Memory Usage: 160.68 MB, less than 12.66% of C++ online submissions
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
const int MX = 1e4+1;


class Solution {
    unordered_map<ll, int> memo;
    string s;
    int n, k;
public:
    int maxPartitionsAfterOperations(string s, int k) {
        this->s = s;
        this->k = k;
        n = s.length();
        return dfs(0, 0, false);
    }
    int dfs(int idx, int cur_set, bool changed) {
        if (idx == n) return 1;
        ll arg_mask = (ll) idx << 32 | cur_set << 1 | changed;
        if (memo.find(arg_mask) != memo.end()) return memo[arg_mask];
        int new_set = cur_set | (1 << (s[idx] - 'a'));
        int bit_num = __builtin_popcount(new_set);
        int res = 0;
        if (bit_num > this->k) {
            res = dfs(idx + 1, (1 << (s[idx] - 'a')), changed) + 1;
        } else {
            res = dfs(idx + 1, new_set, changed);
        }

        if (!changed) {
            for (int i = 0; i < 26; i++) {
                new_set = cur_set | (1 << i);
                bit_num = __builtin_popcount(new_set);
                if (bit_num > this->k) {
                    res = max(res, dfs(idx + 1, (1 << i), !changed) + 1);
                } else {
                    res = max(res, dfs(idx + 1, new_set, !changed));
                }
            }
        }
        return memo[arg_mask] = res;
    }
};