/**
 * Source: jpeg.ly/QAeOl
 * Date: 2023/12/23
 * Skill:
 * Ref:
 * Runtime: 108 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 30.38 MB, less than 70.00% of C++ online submissions
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


#define ll long long
using namespace std;


class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res;
        int idx = 0, len = sentence.length();
        while (idx < len) {
            bool is_price = true;
            int pos = idx + 1;
            while (pos < len && sentence[pos] != ' ') {
                if (!isdigit(sentence[pos++])) is_price = false;
            }
            if (is_price && sentence[idx] == '$' && pos - idx > 1) {
                res.push_back('$');
                long double num = stoll(sentence.substr(idx + 1, pos - idx - 1));
                num *= (100.00 - discount) / 100;
                string s = to_string(num);
                string round = s.substr(0, s.find(".") + 3);
                res += round;
            } else {
                res += sentence.substr(idx, pos - idx);
            }
            if (sentence[pos] == ' ') res.push_back(' ');
            idx = pos + 1;
        }
        return res;
    }
};