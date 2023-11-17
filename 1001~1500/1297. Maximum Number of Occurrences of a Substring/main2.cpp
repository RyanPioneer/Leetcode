/**
 * Source: ibit.ly/Vb5qp
 * Date: 2023/11/17
 * Skill: We only need to consider the minSize, because we only care the maximum
 *          number of occurrences of any substring. For example, the occurrence number of
 *          "abcd" must be less than or equal to "abc".
 * Runtime: 28 ms, faster than 98.31% of C++ online submissions
 * Memory Usage: 11.70 MB, less than 98.49% of C++ online submissions
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

const int MX = 27;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<ll, int> hash2num;
        ll mod = 1e9+7, cur_hash = 0, power = 1;
        int cnt[MX] = {0}, len = s.length(), unique = 0, res = 0;
        for (int i = 0; i < minSize; i++) {
            int c = s[i] - 'a';
            cnt[c]++;
            if (cnt[c] == 1) unique++;
            power = power * MX % mod;
            cur_hash = (cur_hash * MX + c + 1) % mod;
        }
        if (unique <= maxLetters) {
            hash2num[cur_hash]++;
            res = 1;
        }
        for (int right = minSize; right < len; right++) {
            int c = s[right] - 'a', left = s[right - minSize] - 'a';
            cur_hash = (cur_hash * MX + c + 1) % mod;
            cur_hash = (cur_hash - (left + 1) * power % mod + mod) % mod;
            cnt[c]++;
            if (cnt[c] == 1) unique++;
            cnt[left]--;
            if (cnt[left] == 0) unique--;
            if (unique <= maxLetters) {
                hash2num[cur_hash]++;
                res = max(res, hash2num[cur_hash]);
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}