/**
 * Source: twtr.to/AlnUk
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 17 ms, faster than 29.45% of C++ online submissions
 * Memory Usage: 7.08 MB, less than 75.22% of C++ online submissions
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


class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = SZ(s), res = 0, cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            int j = n - 1 - cnt;
            while (j > i && s[j] != s[i]) j--;
            if (j == i) {
                res += n / 2 - j;
            } else {
                int dis = n - 1 - cnt - j;
                res += dis;
                cnt++;
                while (dis--) {
                    swap(s[j], s[j + 1]);
                    j++;
                }
            }
        }
        return res;
    }
};