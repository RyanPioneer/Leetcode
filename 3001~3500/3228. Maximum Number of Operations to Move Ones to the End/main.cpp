/**
 * Source: jpeg.ly/9TRqJ
 * Date: 2025/1/15
 * Skill:
 * Ref:
 * Runtime: 1 ms, faster than 86.64% of C++ online submissions
 * Memory Usage: 15.89 MB, less than 51.03% of C++ online submissions
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
    int maxOperations(string s) {
        int res = 0, oneNum = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                oneNum++;
            } else {
                while (i < n && s[i] == '0') {
                    i++;
                }
                res += oneNum;
                i--;
            }
        }
        return res;
    }
};
