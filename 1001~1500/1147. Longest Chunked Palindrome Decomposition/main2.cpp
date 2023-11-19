/**
 * Source: twtr.to/B3DJR
 * Date: 2023/11/19
 * Skill:
 * Runtime: 3 ms, faster than 74.11% of C++ online submissions
 * Memory Usage: 6.61 MB, less than 84.82% of C++ online submissions
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
    int longestDecomposition(string text) {
        int res = 0, left = 0, right = text.length() - 1, last = text.length();
        int mid = text.length() / 2 + (text.length() % 2);
        while (right >= mid) {
            if (text[left] == text[right]) {
                bool check = true;
                for (int i = 0; right + i < last; i++) {
                    if (text[left + i] != text[right + i]) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    res += 2;
                    left += last - right;
                    last = right;
                }
            }
            right--;
        }
        return res + (left < text.length() / 2 + (text.length() % 2));
    }
};