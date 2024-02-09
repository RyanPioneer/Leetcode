/**
 * Source: is.gd/cca0lA
 * Date: 2024/2/9
 * Skill:
 * Ref:
 * Runtime: 304 ms, faster than 13.92% of C++ online submissions
 * Memory Usage: 39.86 MB, less than 45.15% of C++ online submissions
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

const int carry = 27, MX = 1e6+2, MOD = 1e9+17;


class Solution {
    ULL multi[MX] = {1};
public:
    int minimumTimeToInitialState(string word, int k) {
        ULL left = 0, right = 0;
        int len = word.length(), res = -1;
        for (int i = 0; i < len; i++) {
            multi[i + 1] = multi[i] * carry % MOD;
        }
        for (int i = 0; i < len - 1; i++) {
            left = (left * carry + word[i] - 'a' + 1 + MOD) % MOD;
            right = (right + (word[len - 1 - i] - 'a' + 1) * multi[i] + MOD) % MOD;
            if (left == right && (len - 1 - i) % k == 0) res = (len - 1 - i) / k;
        }
        return res != -1 ? res : len / k + (len % k != 0);
    }
};