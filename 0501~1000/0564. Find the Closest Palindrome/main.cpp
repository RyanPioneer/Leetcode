/**
 * Source: jpeg.ly/AMge-
 * Date: 2023/12/21
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.43 MB, less than 90.95% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    string nearestPalindromic(string n) {
        if (n == "1") return "0";
        string a = getGreater(n), b = getSmaller(n);
        if (abs(stoll(b) - stoll(n)) <= abs(stoll(a) - stoll(n))) return b;
        else return a;
    }
    string getGreater(string &n) {
        string s = n;
        int len = n.length();
        for (int i = 0; i < len / 2; i++) {
            s[len - 1 - i] = s[i];
        }
        if (s > n) return s;
        int carry = 1;
        for (int i = len / 2 - (1 - len % 2), j = i + (1 - len % 2); i >= 0; i--, j++) {
            if (s[i] - '0' + carry == 10) {
                s[i] = '0';
                carry = 1;
            } else {
                s[i] += carry;
                carry = 0;
            }
            s[j] = s[i];
        }
        if (carry == 1) {
            s = string(len + 1, '0');
            s[0] = s.back() = '1';
        }
        return s;
    }
    string getSmaller(string &n) {
        string s = n;
        int len = n.length();
        for (int i = 0; i < len / 2; i++) {
            s[len - 1 - i] = s[i];
        }
        if (s < n) return s;
        int carry = -1;
        for (int i = len / 2 - (1 - len % 2), j = i + (1 - len % 2); i >= 0; i--, j++) {
            if (s[i] - '0' + carry < 0) {
                s[i] = '9';
                carry = -1;
            } else {
                s[i] += carry;
                carry = 0;
            }
            s[j] = s[i];
        }
        if (s[0] == '0') {
            s = string(len - 1, '9');
        }
        return s;
    }
};