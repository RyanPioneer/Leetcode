/**
 * Source: t.ly/G2Mi2
 * Date: 2023/11/13
 * Skill:
 * Runtime: 20 ms, faster than 99.23% of C++ online submissions
 * Memory Usage: 10.96 MB, less than 99.38% of C++ online submissions
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

const int MX = 128;

class Solution {
public:
    string sortVowels(string s) {
        int freq[MX] = {0}, idx = 0;
        for (auto &c: s) {
            if (isVowel(c)) {
                freq[c]++;
            }
        }
        for (auto &c: s) {
            if (isVowel(c)) {
                while (freq[idx] == 0) idx++;
                c = idx;
                freq[idx]--;
            }
        }
        return s;
    }
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
                || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};


int main() {
    Solution s;
}