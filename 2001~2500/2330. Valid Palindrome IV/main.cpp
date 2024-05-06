/**
 * Source: t.ly/Qz85U
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 7 ms, faster than 80.57% of C++ online submissions
 * Memory Usage: 9.52 MB, less than 20.38% of C++ online submissions
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
const int MX = 1e9+7;


class Solution {
public:
    bool makePalindrome(string s) {
        int cnt = 0, len = s.length();
        for (int left = 0, right = len - 1; left < right; left++, right--) {
            if (s[left] != s[right]) {
                cnt++;
                if (cnt > 2) {
                    break;
                }
            }
        }
        return cnt <= 2;
    }
};