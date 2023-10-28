/**
 * Source: tinyurl.com/yl9vcvk5
 * Date: 2023/10/28
 * Skill:
 * Runtime: 51 ms, faster than 92.59% of C++ online submissions
 * Memory Usage: 14.77 MB, less than 86.20% of C++ online submissions
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

const int MX = 10;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ll res = 0;
        int cnt[1 << MX] = {0}, cur_num = 0;
        cnt[0] = 1;
        for (auto c: word) {
            cur_num ^= (1 << (c - 'a'));
            res += cnt[cur_num];
            for (int i = 0; i < MX; i++) {
                int num = cur_num ^ (1 << i);
                res += cnt[num];
            }
            cnt[cur_num]++;
        }
        return res;
    }
};


int main() {
//    Solution s;
}