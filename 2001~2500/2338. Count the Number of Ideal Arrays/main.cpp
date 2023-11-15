/**
 * Source: ibit.ly/mPgFm
 * Date: 2023/11/15
 * Skill:
 * Runtime: 53 ms, faster than 82.72% of C++ online submissions
 * Memory Usage: 7.92 MB, less than 95.06% of C++ online submissions
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


#define ll long long

const int MX = 1e4+1;
const int MXEXP = 14;


class Solution {
public:
    int idealArrays(int n, int maxValue) {
        ll comb[MX + MXEXP][MXEXP] = {0}, mod = 1e9+7, res = 1;
        comb[0][0] = 1;
        for (int i = 1; i <= n + MXEXP; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, MXEXP - 1); j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
            }
        }
        vector<int> primes = Eratosthenes(maxValue);
        for (int i = 2; i <= maxValue; i++) {
            int num = i;
            ll cnt = 1;
            for (auto &j: primes) {
                if (num == 1) break;
                int t = 0;
                while (num % j == 0) {
                    t++;
                    num /= j;
                }
                cnt = cnt * comb[n + t - 1][t] % mod;
            }
            res = (res + cnt) % mod;
        }
        return res;
    }
    vector<int>Eratosthenes(int n) {
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