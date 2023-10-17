/**
 * Source: twtr.to/Z4ZdN
 * Date: 2023/10/16
 * Skill:
 * Runtime: 153 ms, faster than 8.85% of C++ online submissions
 * Memory Usage: 71.90 MB, less than 5.24% of C++ online submissions
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
    int diagonalPrime(vector<vector<int>>& nums) {
        function<vector<int>(int)> find_primes;
        find_primes = [=](int limit) {
            vector<int> prime_list(limit + 1, 0);
            prime_list[0] = prime_list[1] = 1;
            for (int i = 2; i <= sqrt(limit); i++) {
                if (prime_list[i] != 0)
                    continue;
                int j = i * i;
                while (j <= limit) {
                    prime_list[j] = 1;
                    j += i;
                }
            }
            return prime_list;
        };

        int res = 0, sz = nums.size(), maximum = 0;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                maximum = max(maximum, nums[i][j]);

        vector<int> prime_list = find_primes(maximum);
        for (int i = 0; i < sz; i++) {
            if (prime_list[nums[i][i]] == 0)
                res = max(res, nums[i][i]);
            if (prime_list[nums[i][sz - 1 - i]] == 0)
                res = max(res, nums[i][sz - 1 - i]);
        }
        return res;
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