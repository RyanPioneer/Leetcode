/**
 * Source: t.ly/oyEnm
 * Date: 2023/11/14
 * Skill:
 * Runtime: 5 ms, faster than 99.30% of C++ online submissions
 * Memory Usage: 7.13 MB, less than 99.30% of C++ online submissions
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


const int MX = 101;

class Solution {
    int len, diff, used[10];
    bool can_change_even;
public:
    string findLexSmallestString(string s, int a, int b) {
        len = s.length(), diff = a % 10;
        b %= len;
        can_change_even = (b % 2 == 1);
        int visited[MX] = {0}, idx = 0;
        string res = s;
        while (visited[idx] == 0) {
            visited[idx] = 1;
            res = min(res, get_res(s, idx));
            idx = (idx - b + len) % len;
        }
        return res;
    }
    string get_res(string &s, int idx) {
        int add[2] = {0};
        add[1] = find_min(s[(idx + 1) % len] - '0');
        if (can_change_even) add[0] = find_min(s[idx] - '0');
        string t;
        for (int i = 0; i < len; i++) {
            int pos = (idx + i) % len;
            int num = (s[pos] - '0' + add[i % 2]) % 10;
            t.push_back('0' + num);
        }
        return t;
    }
    int find_min(int cur) {
        for (int i = 0; i < 10; i++) used[i] = 0;
        int mi = cur;
        while (used[cur] == 0) {
            mi = min(mi, cur);
            used[cur] = 1;
            cur = (cur + diff) % 10;
        }
        return (mi - cur + 10) % 10;
    }
};


int main() {
    Solution s;
}