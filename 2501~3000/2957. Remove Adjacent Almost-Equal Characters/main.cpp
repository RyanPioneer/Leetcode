/**
 * Source: jpeg.ly/Y-krP
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 5 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.62 MB, less than 100.00% of C++ online submissions
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


const int MX = 101;


class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int res = 0;
        for (int i = 1; i < word.length(); i++) {
            if (abs(word[i] - word[i - 1]) <= 1) {
                res++;
                i++;
            }
        }
        return res;
    }
};