/**
 * Source: twtr.to/tdlrI
 * Date: 2023/11/19
 * Skill:
 * Runtime: 3 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.20 MB, less than 85.71% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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
    int findMinimumOperations(string s1, string s2, string s3) {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        int right = min({len1, len2, len3}) - 1;
        for (int i = right; i >= 0; i--) {
            if (s1[i] != s2[i] || s1[i] != s3[i]) {
                right = i - 1;
            }
        }
        return right >= 0 ? len1 + len2 + len3 - (right + 1) * 3 : -1;
    }
};