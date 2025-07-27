/**
 * Source: tinyurl.com/2bzqdgns
 * Date: 2025/7/27
 * Skill:
 * Ref:
 * Runtime: 60 ms, faster than 42.41% of C++ online submissions
 * Memory Usage: 204.66 MB, less than 87.99% of C++ online submissions
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
#define ll long long
const int MOD = 1e9 + 7;

class Solution {
   public:
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size(), first = 0, second = 0, third = 0;
        vector<int> result(n, 0);

        auto cmp = [](const string& a, const string& b) {
            for (int i = 0, j = 0; i < a.size() && j < b.size(); ++i, ++j) {
                if (a[i] != b[j]) return i;
            }
            return int(min(a.size(), b.size()));
        };

        for (int i = 0; i < n - 1; ++i) {
            int length = cmp(words[i], words[i + 1]);
            if (length >= first) {
                third = second;
                second = first;
                first = length;
            } else if (length >= second) {
                third = second;
                second = length;
            } else if (length >= third) {
                third = length;
            }
        }

        vector<int> res;

        for (int i = 0; i < n; ++i) {
            int len = 0, prev = 0, next = 0;
            if (i - 1 >= 0 && i + 1 < n) {
                len = cmp(words[i - 1], words[i + 1]);
            }
            if (i - 1 >= 0) {
                prev = cmp(words[i - 1], words[i]);
            }
            if (i + 1 < n) {
                next = cmp(words[i], words[i + 1]);
            }
            if (prev < next) swap(prev, next);
            if (first != prev) {
                res.push_back(max(first, len));
            } else if (second != next) {
                res.push_back(max(second, len));
            } else {
                res.push_back(max(third, len));
            }
        }
        return res;
    }
};
