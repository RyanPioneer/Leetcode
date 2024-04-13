/**
 * Source: is.gd/ObWfe3
 * Date: 2024/4/7
 * Skill:
 * Ref:
 * Runtime: 43 ms, faster than 74.95% of C++ online submissions
 * Memory Usage: 17.20 MB, less than 97.99% of C++ online submissions
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

const int MX = 26;


class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[MX] = {0}, mi = INT32_MAX, res = INT32_MAX;;
        for (auto &c: word) freq[c - 'a']++;
        for (int i = 0; i < MX; i++) {
            int cnt = 0;
            if (freq[i] == 0) continue;
            for (int j = 0; j < MX; j++) {
                if (freq[j] < freq[i]) {
                    cnt += freq[j];
                } else if (freq[j] - freq[i] > k) {
                    cnt += freq[j] - freq[i] - k;
                }
            }
            res = min(res, cnt);
        }
        return res;
    }
};