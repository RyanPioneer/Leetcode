/**
 * Source: https://rb.gy/2pwhy
 * Date: 2023/9/6
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 8.28 MB, less than 7.82% of C++ online submissions
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
    int res = 0, sz;
    string n_string;
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        n_string = to_string(n);
        sz = digits.size();
        for (int i = 1; i < n_string.length(); i++)
            res += pow(sz, i);
        dfs(0, digits);
        return res;
    }
    void dfs(int pos, vector<string>& digits) {
        if (pos == n_string.length()) {
            res++;
            return;
        }
        for (auto i: digits) {
            if (i[0] < n_string[pos])
                res += pow(sz, n_string.length() - pos - 1);
            if (i[0] == n_string[pos])
                dfs(pos + 1, digits);
        }
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
//    Solution s;
    string s = "1";
    cout << s[0] - '0';
}