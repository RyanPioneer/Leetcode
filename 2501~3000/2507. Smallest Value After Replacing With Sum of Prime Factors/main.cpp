/**
 * Source: t.ly/rgaH7
 * Date: 2023/11/14
 * Skill:
 * Runtime: 42 ms, faster than 26.70% of C++ online submissions
 * Memory Usage: 16.04 MB, less than 20.98% of C++ online submissions
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
#include <list>


using namespace std;


const int MX = 1e5+1;


class Solution {
public:
    int smallestValue(int n) {
        int res = n;
        vector<int> primes = get_prime(n);
        while (n > 1) {
            int fac = 0, time = 0, prev_n = n;
            for (auto &i: primes) {
                if (i > n) break;
                while (n % i == 0) {
                    time++;
                    fac += i;
                    n /= i;
                }
            }
            if (time == 1 || fac == prev_n) break;
            res = min(res, fac);
            n = fac;
        }
        return res;
    }
    vector<int> get_prime(int n) {
        vector<int> primes;
        int visited[MX] = {0};
        for (int i = 2; i <= sqrt(n); i++) {
            if (visited[i] == 1) continue;
            int j = i * i;
            while (j <= n) {
                visited[j] = 1;
                j += i;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (visited[i] == 0) {
                primes.push_back(i);
            }
        }
        return primes;
    }
};


int main() {
    Solution s;
}