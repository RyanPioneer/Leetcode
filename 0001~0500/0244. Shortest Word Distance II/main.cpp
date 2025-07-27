/**
 * Source: tinyurl.com/2a37an4f
 * Date: 2025/4/20
 * Skill:
 * Ref:
 * Runtime: 10 ms, faster than 71.57% of C++ online submissions
 * Memory Usage: 26.30 MB, less than 59.14% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class WordDistance {
    unordered_map<string, vector<int>> wordIndexMap;

   public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            wordIndexMap[wordsDict[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int res = INT_MAX, idx1 = 0, idx2 = 0;
        int sz1 = wordIndexMap[word1].size(), sz2 = wordIndexMap[word2].size();
        while (idx1 < sz1 && idx2 < sz2) {
            res = min(res, abs(wordIndexMap[word1][idx1] -
                               wordIndexMap[word2][idx2]));
            if (wordIndexMap[word1][idx1] < wordIndexMap[word2][idx2]) {
                ++idx1;
            } else {
                ++idx2;
            }
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
