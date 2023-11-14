/**
 * Source: t.ly/BHGvl
 * Date: 2023/11/14
 * Skill:
 * Runtime: 31 ms, faster than 75.60% of C++ online submissions
 * Memory Usage: 19.10 MB, less than 87.52% of C++ online submissions
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


const int MX = 1001;


class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int factor[MX] = {0}, res = 0;
        vector<int> prime_list = get_prime();
        for (auto &i: nums) {
            for (auto &j: prime_list) {
                if (j > i) break;
                while (i % j == 0) {
                    factor[j] = 1;
                    i /= j;
                }
            }
        }
        for (auto &j: prime_list) {
            res += factor[j];
        }
        return res;
    }
    vector<int> get_prime() {
        vector<int> primes;
        int visited[MX] = {0};
        for (int i = 2; i <= sqrt(MX); i++) {
            if (visited[i] == 1) continue;
            int j = i * i;
            while (j < MX) {
                visited[j] = 1;
                j += i;
            }
        }
        for (int i = 2; i < MX; i++) {
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