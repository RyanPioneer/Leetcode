/**
 * Source: ibit.ly/dAEEg
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 71 ms, faster than 68.99% of C++ online submissions
 * Memory Usage: 52.23 MB, less than 25.63% of C++ online submissions
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

#define ll long long
const int charNum = 26;

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        ll res = 0;
        int cnt1[charNum] = {0}, cnt2[charNum] = {0}, sz1 = word1.size(), right = 0, feasibleNum = 0;
        for (char c : word2) cnt2[c - 'a']++;
        for (int i = 0; i < charNum; i++) feasibleNum += cnt2[i] == 0;
        for (int left = 0; left < sz1; left++) {
            while (feasibleNum < charNum && right < sz1) {
                cnt1[word1[right++] - 'a']++;
                if (cnt1[word1[right - 1] - 'a'] == cnt2[word1[right - 1] - 'a']) feasibleNum++;
            }
            if (feasibleNum == charNum) {
                res += sz1 - right + 1;
            } else {
                break;
            }
            cnt1[word1[left] - 'a']--;
            if (cnt1[word1[left] - 'a'] == cnt2[word1[left] - 'a'] - 1) feasibleNum--;
        }
        return res;
    }
};
