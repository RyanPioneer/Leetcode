/**
 * Source: tinyurl.com/29rsqyol
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 146 ms, faster than 35.48% of C++ online submissions
 * Memory Usage: 101.76 MB, less than 37.63% of C++ online submissions
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
        int res = INT32_MAX;
        vector<int> pos;

        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word1) {
                pos.push_back(i);
            }
        }
        for (int i = 0; i < wordsDict.size(); i++) {
            if (wordsDict[i] == word2) {
                auto it = upper_bound(begin(pos), end(pos), i);
                if (it != end(pos)) {
                    res = min(res, *it - i);
                }
                if (it != begin(pos)) {
                    if (*prev(it) == i) {
                        if (prev(it) != begin(pos)) {
                            res = min(res, i - *prev(prev(it)));
                        }
                    } else {
                        res = min(res, i - *prev(it));
                    }
                }
            }
        }
        return res;
    }
};