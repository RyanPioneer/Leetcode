/**
 * Source: is.gd/n7vkH7
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 71.47% of C++ online submissions
 * Memory Usage: 32.16 MB, less than 48.71% of C++ online submissions
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
const int charNum = 26;


class Solution {
public:
    int minimumLength(string s) {
        int cnt[charNum] = {0}, res = 0;
        for (char c : s) {
            cnt[c - 'a']++;
        }
        for (int i = 0; i < charNum; i++) {
            if (cnt[i] <= 2) {
                res += cnt[i];
            } else {
                res += 1 + (cnt[i] % 2 == 0);
            }
        }
        return res;
    }
};
