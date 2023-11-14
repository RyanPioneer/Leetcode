/**
 * Source: t.ly/3cNvj
 * Date: 2023/11/14
 * Skill:
 * Runtime: 333 ms, faster than 20.00% of C++ online submissions
 * Memory Usage: 29.03 MB, less than 64.00% of C++ online submissions
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
const int MAXEXP = 14;


class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        ll mod = 1e9+7;
        vector<int> res;
        ll comb[MX + MAXEXP][MAXEXP] = {1};
        for (int i = 1; i < MX + MAXEXP; i++) {
            comb[i][0] = 1;
            for (int j = 1; j <= min(i, MAXEXP - 1); j++) {
                comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
            }
        }
        for (auto &i: queries) {
            int sz = i[0], num = i[1];
            ll way = 1;
            for (int j = 2; j <= num; j++) {
                if (num % j == 0) {
                    int cnt = 0;
                    while (num % j == 0) {
                        cnt++;
                        num /= j;
                    }
                    way = way * comb[cnt + sz - 1][cnt] % mod;
                }
            }
            res.push_back(way);
        }
        return res;
    }
};


int main() {
    Solution s;
}