/**
 * Source: jpeg.ly/YujSw
 * Date: 2023/12/23
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 87.83% of C++ online submissions
 * Memory Usage: 7.02 MB, less than 54.18% of C++ online submissions
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
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        string res;
        int len1 = num1.length(), len2 = num2.length(), cur_len = 0;
        for (int i = 0; i < len1; i++) {
            int carry = 0, num = num1[i] - '0';
            for (int j = 0; j < len2; j++) {
                int cur = (num2[j] - '0') * num;
                carry += cur;
                if (cur_len > i + j) carry += res[i + j] - '0';
                if (cur_len <= i + j) {
                    cur_len++;
                    res.push_back('0' + carry % 10);
                } else {
                    res[i + j] = '0' + carry % 10;
                }
                carry /= 10;
            }
            int idx = i + len2;
            while (carry > 0) {
                if (cur_len <= idx) {
                    cur_len++;
                    res.push_back('0' + carry % 10);
                } else {
                    res[idx] = '0' + carry % 10;
                }
                carry /= 10;
                idx++;
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};