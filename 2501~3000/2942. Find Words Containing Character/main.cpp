/**
 * Source: is.gd/bSIvI0
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 29.17 MB, less than 57.14% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < SZ(words); i++) {
            for (auto &c : words[i]) {
                if (c == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};