/**
 * Source: twtr.to/UiVRy
 * Date: 2023/11/19
 * Skill:
 * Runtime: 29 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 13.50 MB, less than 55.56% of C++ online submissions
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

#define ll long long


class Solution {
public:
    long long minimumSteps(string s) {
        int right = s.length() - 1, left = s.length() - 1;
        ll res = 0;
        while (right >= 0) {
            while (left >= 0 && s[left] == '1') left--;
            if (left <= 0) break;
            if (right >= left) right = left - 1;
            while (right >= 0 && s[right] == '0') right--;
            if (right < 0) break;
            res += left - right;
            s[right] = '0';
            s[left] = '1';
        }
        return res;
    }
};