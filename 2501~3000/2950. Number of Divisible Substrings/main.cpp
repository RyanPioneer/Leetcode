/**
 * Source: ibit.ly/PtbKZ
 * Date: 2024/5/15
 * Skill:
 * Ref:
 * Runtime: 56 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.16 MB, less than 36.59% of C++ online submissions
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


const int MX = 2e3+3;


class Solution {
public:
    int countDivisibleSubstrings(string word) {
        int res = 0, n = word.length(), presum[MX] = {0};

        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + 1;
            if (word[i] - 'a' > 1) {
                presum[i + 1] += 1 + (word[i] - 'a' - 2) / 3;
            }
        }

        for (int left = 0; left < n; ++left) {
            for (int right = left; right < n; right++) {
                int curSum = presum[right + 1] - presum[left];
                if (curSum % (right - left + 1) == 0) {
                    res++;
                }
            }
        }
        return res;
    }
};