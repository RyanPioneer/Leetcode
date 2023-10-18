/**
 * Source: twtr.to/3UEMW
 * Date: 2023/10/18
 * Skill:
 * Runtime: 284 ms, faster than 76.00% of C++ online submissions
 * Memory Usage: 157.71 MB, less than 78.19% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        function<int(ll)> find_digit_sum;
        find_digit_sum = [=](ll num) {
            int total = 0;
            while (num > 0) {
                total += num % 10;
                num /= 10;
            }
            return total;
        };
        string res;
        while (n > 0) {
            int digit_sum = find_digit_sum(n);
            if (digit_sum <= target)
                break;
            int num = 10 - n % 10;
            n /= 10;
            if (num < 10) {
                res.push_back('0' + num);
                n += 1;
            } else
                res.push_back('0');
        }
        if (res.empty())
            return 0;
        reverse(begin(res), end(res));
        return stoll(res);
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}