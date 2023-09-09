/**
 * Source: https://rb.gy/ff6xu
 * Date: 2023/9/9
 * Skill:
 * Runtime: 697 ms, faster than 83.76% of C++ online submissions
 * Memory Usage: 220.92 MB, less than 68.66% of C++ online submissions
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

#define ULL uint64_t

class Solution {
public:
    unordered_map<int, int> length2pos;
    string ss;
    string longestDupSubstring(string s) {
        ss = s;
        int lo = 1, hi = s.length() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            bool found = check_feasible(mid);
            if (found)
                lo = mid;
            else
                hi = mid - 1;
        }
        if (check_feasible(lo))
            return ss.substr(length2pos[lo], lo);
        else
            return "";
    }
    bool check_feasible(int length) {
        unordered_set<ULL> myset;
        ULL base = 27, hash = 0, pow_base_len = 1;
        for (int i = 0; i < length; i++)
            pow_base_len *= base;
        for (int i = 0; i < ss.length(); i++) {
            hash = hash * base + (ss[i] - 'a');
            if (i >= length) {
                hash -= (ss[i - length] - 'a') * pow_base_len;
                if (myset.find(hash) != myset.end()) {
                    length2pos[length] = i - length + 1;
                    return true;
                }
            }
            if (i >= length - 1)
                myset.insert(hash);
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
    string ss = "aa";
    string res = s.longestDupSubstring(ss);
    cout << res << endl;
}