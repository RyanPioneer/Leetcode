/**
 * Source: t.ly/9UTDu
 * Date: 2023/11/12
 * Skill:
 * Runtime: 50 ms, faster than 66.96% of C++ online submissions
 * Memory Usage: 22.23 MB, less than 9.56% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
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
    string smallestBeautifulString(string s, int t) {
        string origin = s;
        char limit = 'a' + t - 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            bool found = false;
            for (char ch = s[i] + 1; ch <= limit; ch++) {
                if (checkOK(s, i, ch)) {
                    found = true;
                    s[i] = ch;
                    for (int k = i + 1; k < s.length(); k++) {
                        for (char c = 'a'; c <= limit; c++) {
                            if (checkOK(s, k, c)) {
                                s[k] = c;
                                break;
                            }
                        }
                    }
                    break;
                }
            }
            if (found) break;
        }
        return s == origin ? "" : s;
    }
    bool checkOK(string &s, int idx, char c) {
        if (idx > 0 && s[idx - 1] == c) return false;
        if (idx > 1 && s[idx - 2] == c) return false;
        return true;
    }
};


int main() {
    Solution s;
}