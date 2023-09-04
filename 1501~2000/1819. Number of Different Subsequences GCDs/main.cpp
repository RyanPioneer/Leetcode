/**
 * Source: https://rb.gy/9ehgy
 * Date: 2023/9/2
 * Skill:
 * Runtime: 2990 ms, faster than 5.49% of C++ online submissions
 * Memory Usage: 419.32 MB, less than 5.49% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
 *      1 <= nums[i] <= 2 * 10 ** 5
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>
#include <deque>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int sz = nums.size(), maximum = *max_element(begin(nums), end(nums)), res = 0;
        unordered_map<int, int>num2gcd;
        for (auto num: nums) {
            for (int i = 1; i <= sqrt(num); i++) {
                if (num % i == 0) {
                    if (num2gcd.find(i) == num2gcd.end())
                        num2gcd[i] = num;
                    else
                        num2gcd[i] = gcd(num2gcd[i], num);
                    if (num2gcd.find(num / i) == num2gcd.end())
                        num2gcd[num / i] = num;
                    else
                        num2gcd[num / i] = gcd(num2gcd[num / i], num);
                }
            }
        }
        for (int i = 1; i <= maximum; i++)
            if (num2gcd[i] == i)
                res++;
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
    Solution s;
    vector<int> nums{1,3,2};
//    cout << res << endl;
}