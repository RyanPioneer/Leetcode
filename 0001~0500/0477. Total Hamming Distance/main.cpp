/**
 * Source: t.ly/aEe7V
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 30 ms, faster than 76.53% of C++ online submissions
 * Memory Usage: 21.39 MB, less than 56.45% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt[31] = {0}, res = 0, n = nums.size();
        for (auto i: nums) {
            for (int j = 0; j < 31; j++) {
                if ((i>>j)&1) cnt[j]++;
            }
        }

        For(i,0,30) {
            res += cnt[i] * (n - cnt[i]);
        }
        return res;
    }
};