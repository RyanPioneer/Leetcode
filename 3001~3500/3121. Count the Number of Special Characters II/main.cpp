/**
 * Source: is.gd/eLEbdC
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 60 ms, faster than 85.71% of C++ online submissions
 * Memory Usage: 22.60 MB, less than 100.00% of C++ online submissions
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

const int MX = 26;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        int res = 0, arr[MX] = {0};
        for (auto &c: word) {
            if ('a' <= c && c <= 'z') {
                if (arr[c - 'a'] <= 1) {
                    arr[c - 'a'] = 1;
                } else {
                    arr[c - 'a'] = 3;
                }
            } else {
                if (arr[c - 'A'] == 1 || arr[c - 'A'] == 2) {
                    arr[c - 'A'] = 2;
                } else {
                    arr[c - 'A'] = 3;
                }
            }
        }
        for (int i = 0; i < MX; i++) {
            if (arr[i] == 2) {
                res++;
            }
        }
        return res;
    }
};