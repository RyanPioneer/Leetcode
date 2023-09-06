/**
 * Source: https://rb.gy/2pwhy
 * Date: 2023/9/6
 * Skill:
 * Runtime: 3 ms, faster than 40.32% of C++ online submissions
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
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int res = 0;
        vector<int> n_digits;
        while (n > 0) {
            n_digits.push_back(n % 10);
            n /= 10;
        }
        for (int i = 1; i < n_digits.size(); i++)
            res += pow(digits.size(), i);
        int pos = n_digits.size() - 1;
        while (pos >= 0) {
            bool flag = true;
            for (int i = 0; i < digits.size(); i++) {
                if (digits[i][0] - '0' < n_digits[pos])
                    res += pow(digits.size(), pos);
                else if (digits[i][0] - '0' == n_digits[pos]) {
                    flag = false;
                    if (pos == 0)
                        res++;
                    break;
                } else{
                    return res;
                }
            }
            if (flag)
                break;
            pos--;
        }
        return res;
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