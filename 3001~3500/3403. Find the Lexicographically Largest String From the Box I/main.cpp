/**
 * Source: ibit.ly/TB8Bg
 * Date: 2025/1/5
 * Skill:
 * Ref:
 * Runtime: 867 ms, faster than 9.11% of C++ online submissions
 * Memory Usage: 90.29 MB, less than 55.67% of C++ online submissions
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


class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        int n = word.size();
        string res;
        if (numFriends == 2) {
            for (int i = 0; i < n - 1; i++) {
                string s1 = word.substr(0, i + 1);
                string s2 = word.substr(i + 1);
                res = max(res, max(s1, s2));
            }
            return res;
        }
        for (int i = 0; i < n; i++) {
            string cur;
            for (int end = i; end < n; end++) {
                int len = end - i + 1;
                if (n - len < numFriends - 1) {
                    break;
                }
                cur.push_back(word[end]);
                if (res.size() >= cur.size() && res[len-1] > cur[len-1]) break;
                if (res < cur) {
                    res = cur;
                }
            }
        }
        return res;
    }
};
