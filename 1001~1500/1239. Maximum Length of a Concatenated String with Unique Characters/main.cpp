/**
 * Source: ibit.ly/39oxO
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 13 ms, faster than 75.61% of C++ online submissions
 * Memory Usage: 9.63 MB, less than 92.81% of C++ online submissions
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

const int MX = 16;


class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size(), cnt[26], res = 0;
        bool valid[MX];
        int mask[MX] = {0};
        for (int i = 0; i < n; i++) {
            int num = 0;
            fill(cnt, cnt + 26, 0);
            bool check = true;
            for (auto &j: arr[i]) {
                cnt[j - 'a']++;
                if (cnt[j - 'a'] > 1) {
                    check = false;
                    break;
                }
                num |= 1 << (j - 'a');
            }
            valid[i] = check;
            mask[i] = num;
        }

        for (int state = 1; state < (1 << n); state++) {
            int curMask = 0;
            bool check = true;
            for (int j = 0; j < n; j++) {
                if (state >> j & 1) {
                    if (!valid[j] || (curMask & mask[j]) > 0) {
                        check = false;
                        break;
                    }
                    curMask |= mask[j];
                }
            }
            if (check) {
                res = max(res, __builtin_popcount(curMask));
            }
        }
        return res;
    }
};