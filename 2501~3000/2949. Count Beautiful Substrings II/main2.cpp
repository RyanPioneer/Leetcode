/**
 * Source: is.gd/nrWNJh
 * Date: 2023/11/27
 * Skill:
 * Ref:
 * Runtime: 78 ms, faster than 92.86% of C++ online submissions
 * Memory Usage: 26.72 MB, less than 50.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
typedef pair<int, int> PII;
const int MX = 5 * 1e4 + 1;


class Solution {
public:
    long long beautifulSubstrings(string s, int k) {
        ll res = 0;
        int diff = 0, k_sqrt = find_k_sqrt(4 * k);
        unordered_map<int, int> mp;
        mp[(k_sqrt - 1) * MX] = 1;
        for (int i = 0; i < s.length(); i++) {
            diff += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') ? 1 : -1;
            res += mp[i % k_sqrt * MX + diff]++;
        }
        return res;
    }
    int find_k_sqrt(int k) {
        int res = 1;
        for (int i = 2; i * i <= k; i++) {
            int j = i * i;
            while (k % j == 0) {
                res *= i;
                k /= j;
            }
            if (k % i == 0) {
                k /= i;
                res *= i;
            }
        }
        return res * k;
    }
};