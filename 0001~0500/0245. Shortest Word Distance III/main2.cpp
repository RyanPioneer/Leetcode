/**
 * Source: tinyurl.com/29rsqyol
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 136 ms, faster than 70.97% of C++ online submissions
 * Memory Usage: 101.06 MB, less than 83.87% of C++ online submissions
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
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int res = INT32_MAX, pos1 = INT32_MAX, pos2 = INT32_MAX;

        for (int i = 0; i < wordsDict.size(); i++) {
            int p1 = pos1, p2 = pos2;

            if (wordsDict[i] == word1) {
                res = min(res, abs(i - pos2));
                p1 = i;
            }
            if (wordsDict[i] == word2) {
                res = min(res, abs(i - pos1));
                p2 = i;
            }
            pos1 = p1;
            pos2 = p2;
        }
        return res;
    }
};