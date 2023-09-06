/**
 * Source: https://rb.gy/jsz6d
 * Date: 2023/9/6
 * Skill:
 * Runtime: 76 ms, faster than 50.33% of C++ online submissions
 * Memory Usage: 16.97 MB, less than 56.35% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    bool isItPossible(string word1, string word2) {
        unordered_map<char, int> map1, map2;
        for (auto c: word1)
            map1[c]++;
        for (auto c: word2)
            map2[c]++;
        int sz1 = map1.size(), sz2 = map2.size();
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                char a = char('a' + i), b = char('a' + j);
                if (map1.find(a) == map1.end() || map2.find(b) == map2.end())
                    continue;
                int cnt1 = sz1, cnt2 = sz2;
                if (i == j) {
                    if (cnt1 == cnt2)
                        return true;
                    else
                        continue;
                }
                if (map1[a] == 1)
                    cnt1--;
                if (map2.find(a) == map2.end())
                    cnt2++;
                if (map1.find(b) == map1.end())
                    cnt1++;
                if (map2[b] == 1)
                    cnt2--;
                if (cnt1 == cnt2)
                    return true;
            }
        }
        return false;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    string word1 = "aa", word2 = "ab";
    bool res = s.isItPossible(word1, word2);
}