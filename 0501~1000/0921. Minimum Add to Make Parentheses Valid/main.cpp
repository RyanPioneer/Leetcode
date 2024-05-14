/**
 * Source: ibit.ly/9Yry7
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.34 MB, less than 89.72% of C++ online submissions
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


class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, cnt = 0;
        for (auto &c: s) {
            if (c == '(') {
                cnt++;
            } else {
                if (cnt == 0) {
                    res++;
                } else {
                    cnt--;
                }
            }
        }
        return res + cnt;
    }
};