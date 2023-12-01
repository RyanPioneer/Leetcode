/**
 * Source: jpeg.ly/i9E0G
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 71.01% of C++ online submissions
 * Memory Usage: 11.66 MB, less than 95.20% of C++ online submissions
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
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int p2w1 = 0, p2w2 = 0, p2s1 = 0, p2s2 = 0, len1 = word1.size(), len2 = word2.size();
        while (p2w1 < len1 && p2w2 < len2) {
            if (word1[p2w1][p2s1++] != word2[p2w2][p2s2++]) return false;
            if (p2s1 == word1[p2w1].size()) {
                p2w1++;
                p2s1 = 0;
            }
            if (p2s2 == word2[p2w2].size()) {
                p2w2++;
                p2s2 = 0;
            }
        }
        return p2w1 == word1.size() && p2w2 == word2.size();
    }
};