/**
 * Source: is.gd/mlI9wS
 * Date: 2024/4/20
 * Skill:
 * Ref:
 * Runtime: 332 ms, faster than 40.32% of C++ online submissions
 * Memory Usage: 289.72 MB, less than 38.71% of C++ online submissions
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


class InfiniteStream {
public:
    InfiniteStream(vector<int> bits);
    int next();
};


class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        int n = pattern.size();
        vector<int> kmp(n);

        function<void()> helper = [&]() {
            int len = 0;

            for (int i = 1; i < n; i++) {
                while (len > 0 && pattern[len] != pattern[i]) {
                    len = kmp[len - 1];
                }
                if (pattern[len] == pattern[i]) len++;
                kmp[i] = len;
            }
        };

        helper();

        int pos = 0, num = 0;

        while (true) {
            int i = stream->next();

            while (pos > 0 && pattern[pos] != i) {
                pos = kmp[pos - 1];
            }
            if (pattern[pos] == i) pos++;
            if (pos == n) return num - n + 1;
            num++;
        }
    }
};