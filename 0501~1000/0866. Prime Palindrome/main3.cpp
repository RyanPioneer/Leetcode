/**
 * Source: https://rb.gy/ao5e4
 * Date: 2023/9/16
 * Skill: 注意11為因數的條件
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.60 MB, less than 8.63% of C++ online submissions
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int primePalindrome(int n) {
        if (8 <= n && n <= 11)
            return 11;
        int lo = pow(10, (int)to_string(n).length() / 2);
        for (int i = lo; i < 20000; i++) {
            int num = get_palin(i);
            if (num >= n && check_prime(num))
                return num;
        }
        return -1;
    }
    bool check_prime(int n) {
        if (n == 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                return n == i;
        return true;
    }
    int get_palin(int num) {
        int res = num;
        num /= 10;
        while (num > 0) {
            res = res * 10 + num % 10;
            num /= 10;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
    int res = s.primePalindrome(3073704);
    cout << res << endl;
}