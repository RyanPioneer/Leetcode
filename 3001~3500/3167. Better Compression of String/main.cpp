/**
 * Source: t.ly/QQd9f
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 22 ms, faster than 90.32% of C++ online submissions
 * Memory Usage: 14.85 MB, less than 90.32% of C++ online submissions
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
    string betterCompression(string compressed) {
        int cnt[26] = {0};
        for (int i = 0; i < compressed.length(); i++) {
            char c = compressed[i];
            int freq = 0;
            while (i+1 < compressed.length() && isdigit(compressed[i+1])) {
                i++;
                freq = freq * 10 + (compressed[i] - '0');
            }
            cnt[c - 'a'] += freq;
        }

        string res;
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                res.push_back('a' + i);
                res += to_string(cnt[i]);
            }
        }
        return res;
    }
};