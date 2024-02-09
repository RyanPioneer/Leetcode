/**
 * Source: is.gd/3N5SMU
 * Date: 2024/2/9
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.14 MB, less than 75.11% of C++ online submissions
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
typedef unsigned long long ULL;

const int MX = 1e6+1;


class Solution {
    int len, dp[MX] = {0};
public:
    int minimumTimeToInitialState(string word, int k) {
        len = word.length();
        longestPrefix(word);
        int cur_len = dp[len - 1];
        while (cur_len > 0) {
            if ((len - cur_len) % k == 0) return (len - cur_len) / k;
            cur_len = dp[cur_len - 1];
        }
        return len / k + (len % k != 0);
    }
    void longestPrefix(string &word) {
        for (int i = 1; i < len; i++) {
            int cur_len = dp[i - 1];
            while (cur_len > 0 && word[cur_len] != word[i]) cur_len = dp[cur_len - 1];
            dp[i] = cur_len + (word[i] == word[cur_len]);
        }
    }
};