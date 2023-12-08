/**
 * Source: is.gd/G8Rs7i
 * Date: 2023/12/8
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.76 MB, less than 5.52% of C++ online submissions
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
    int max_len, n2;
    string res;
public:
    int findKthNumber(int n, int k) {
        if (n < 10) return k;
        string num = to_string(n);
        max_len = num.length();
        n2 = n;
        for (int i = 1; i <= 9; i++) {
            if (k == 1) return i;
            int comb = 1;
            for (int j = 2, l = 10; j < max_len; j++, l *= 10) comb += l;
            if (i > num[0] - '0') comb += 0;
            else if (i == num[0] - '0') comb += n - i * pow(10, max_len - 1) + 1;
            else comb += pow(10, max_len - 1);
            if (comb >= k) {
                res.push_back('0' + i);
                helper(num, 1, k - 1, i == num[0] - '0', i > num[0] - '0');
                break;
            } else {
                k -= comb;
            }
        }
        return stoi(res);
    }
    void helper(string &num, int idx, int k, bool equal, bool bigger) {
        n2 -= (num[idx - 1] - '0') * pow(10, max_len - idx);
        if (idx == max_len - 1) {
            res.push_back('0' + k - 1);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            if (k == 1) {
                res.push_back('0' + i);
                return;
            }
            int comb = 1;
            for (int j = idx + 2, l = 10; j < max_len; j++, l *= 10) comb += l;
            if (bigger) comb += 0;
            else if (equal && i > num[idx] - '0') comb += 0;
            else if (equal && i == num[idx] - '0') comb += n2 - i * pow(10, max_len - idx - 1) + 1;
            else comb += pow(10, max_len - idx - 1);
            if (comb >= k) {
                res.push_back('0' + i);
                helper(num, idx + 1, k - 1, equal && i == num[idx] - '0', bigger || (equal && i > num[idx] - '0'));
                return;
            } else {
                k -= comb;
            }
        }
    }
};