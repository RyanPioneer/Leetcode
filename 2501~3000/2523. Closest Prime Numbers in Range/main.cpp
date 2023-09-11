/**
 * Source: https://rb.gy/dml21
 * Date: 2023/9/11
 * Skill:
 * Runtime: 153 ms, faster than 80.07% of C++ online submissions
 * Memory Usage: 20.55 MB, less than 40.53% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= left <= right <= 10 ** 6
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
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> res(2, -1);
        vector<int> prime_list = find_prime(left, right);
        if (prime_list.size() < 2)
            return res;
        res[0] = prime_list[0];
        res[1] = prime_list[1];
        for (int i = 1; i < prime_list.size() - 1; i++)
            if (prime_list[i + 1] - prime_list[i] < res[1] - res[0]) {
                res[0] = prime_list[i];
                res[1] = prime_list[i + 1];
            }
        return res;
    }
    vector<int> find_prime(int left, int right) {
        vector<int> prime_list;
        vector<bool> visited(right + 1, false);
        for (int i = 2; i <= sqrt(right); i++) {
            if (visited[i])
                continue;
            int j = i * i;
            while (j <= right) {
                visited[j] = true;
                j += i;
            }
        }
        for (int i = max(2, left); i <= right; i++)
            if (!visited[i])
                prime_list.push_back(i);
        return prime_list;
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
}