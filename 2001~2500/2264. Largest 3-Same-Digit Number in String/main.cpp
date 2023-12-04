/**
 * Source: jpeg.ly/-RVcS
 * Date: 2023/12/4
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.71 MB, less than 91.88% of C++ online submissions
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
    string largestGoodInteger(string num) {
        string res = "";
        for (int i = 2; i < num.length(); i++) {
            if (num[i] == num[i - 1] && num[i - 1] == num[i - 2]) {
                res = max(res, num.substr(i - 2, 3));
            }
        }
        return res;
    }
};