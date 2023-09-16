/**
 * Source: https://rb.gy/picl2
 * Date: 2023/9/16
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.36 MB, less than 7.29% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      0 <= n <= 10 ** 9
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int sz = s.length(), pos;
        for (pos = 0; pos < sz - 1; pos++)
            if (s[pos] > s[pos + 1])
                break;
        if (pos == sz - 1)
            return n;
        while (pos > 0 && s[pos] == s[pos - 1])
            pos--;
        s[pos]--;
        for (int i = pos + 1; i < sz; i++)
            s[i] = '9';
        return stoi(s);
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
    int res = s.monotoneIncreasingDigits(10);
    cout << res << endl;
}