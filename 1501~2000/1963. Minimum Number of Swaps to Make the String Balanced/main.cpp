/**
 * Source: ibit.ly/PNOUo
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 87 ms, faster than 96.80% of C++ online submissions
 * Memory Usage: 32.38 MB, less than 73.13% of C++ online submissions
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
    int minSwaps(string s) {
        int res = 0, cnt = 0;
        for (auto &c: s) {
            if (c == '[') {
                cnt++;
            } else {
                if (cnt <= 0) {
                    res++;
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
        return res;
    }
};