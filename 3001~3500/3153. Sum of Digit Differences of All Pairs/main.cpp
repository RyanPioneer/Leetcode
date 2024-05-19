/**
 * Source: t.ly/8EkKp
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 132 ms, faster than 83.33% of C++ online submissions
 * Memory Usage: 103.35 MB, less than 50.00% of C++ online submissions
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
#define MK make_pair
#define SZ(X) ((int)(X).size())
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int bitNum = 0, a = nums.back(), n = nums.size();
        while (a) {
            bitNum++;
            a/=10;
        }
        vector<vector<int>> cnt(bitNum, vector<int>(10, 0));
        for (auto i: nums) {
            for (int j = 0; j < bitNum; j++) {
                cnt[j][i%10]++;
                i/=10;
            }
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < bitNum; j++) {
                res += n - i - cnt[j][nums[i]%10];
                cnt[j][nums[i]%10]--;
                nums[i] /= 10;
            }
        }
        return res;
    }
};