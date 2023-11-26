/**
 * Source: is.gd/fhlnOr
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 32 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.90 MB, less than 50.00% of C++ online submissions
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
#include <cstring>


using namespace std;


class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int res = 0, len = s.length();
        for (int i = 0; i < len; i++) {
            int v = 0, c = 0;
            for (int j = i; j < len; j++) {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                    v++;
                } else {
                    c++;
                }
                if (v == c && v * c % k == 0) res++;
            }
        }
        return res;
    }
};