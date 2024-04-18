/**
 * Source: is.gd/VstQhO
 * Date: 2024/4/18
 * Skill:
 * Ref:
 * Runtime: 420 ms, faster than 58.06% of C++ online submissions
 * Memory Usage: 12.01 MB, less than 34.68% of C++ online submissions
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
    string longestSubsequenceRepeatedK(string s, int k) {
        int len = s.length();

        function<bool(string)> check = [&](string a) {
            int idx = 0, num = 0, n = a.length();
            for (int i = 0; i < len; i++) {
                if (s[i] == a[idx]) {
                    idx++;
                    if (idx == n) {
                        num++;
                        idx = 0;
                    }
                }
            }
            return num >= k;
        };

        queue<string> q;
        string ss = "", res;

        q.push(ss);
        while (!q.empty()) {
            for (char i = 'a'; i <= 'z'; i++) {
                string a = q.front();
                a.push_back(i);
                if (check(a)) {
                    q.push(a);
                    if (a.length() > res.length() || (a.length() == res.length() && a > res)) {
                        res = a;
                    }
                }
            }
            q.pop();
        }
        return res;
    }
};