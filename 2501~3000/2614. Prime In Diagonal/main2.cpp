/**
 * Source: twtr.to/Z4ZdN
 * Date: 2023/10/16
 * Skill:
 * Runtime: 94 ms, faster than 55.47% of C++ online submissions
 * Memory Usage: 35.90 MB, less than 29.54% of C++ online submissions
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
        function<bool(int)> check_prime;
        check_prime = [=](int num) {
            if (num < 2 || (num > 2 && num % 2 == 0) || (num > 3 && num % 3 == 0))
                return false;
            for (int i = 2; i <= sqrt(num); i++)
                if (num % i == 0)
                    return false;
            return true;
        };

        int res = 0, sz = nums.size(), maximum = 0;
        for (int i = 0; i < sz; i++) {
            if (check_prime(nums[i][i]))
                res = max(res, nums[i][i]);
            if (check_prime(nums[i][sz - 1 - i]))
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