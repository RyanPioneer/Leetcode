/**
 * Source: is.gd/3elMSB
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 205 ms, faster than 88.26% of C++ online submissions
 * Memory Usage: 260.33 MB, less than 64.30% of C++ online submissions
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
    int minimumLevels(vector<int>& possible) {
        int n = possible.size(), total = 0, left = 0;

        for (int i = 0; i < n; i++) {
            total += (possible[i] == 0 ? -1 : 1);
        }
        for  (int i = 0; i < n - 1; i++) {
            left += (possible[i] == 0 ? -1 : 1);
            if (left > total - left) return i + 1;
        }
        return -1;
    }
};