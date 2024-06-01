/**
 * Source: t.ly/P4nLt
 * Date: 2024/6/1
 * Skill:
 * Ref:
 * Runtime: 68 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 60.40 MB, less than 91.64% of C++ online submissions
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


class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int, int> pos, neg;
        int zero = 0;
        for (auto &i: arr) {
            if (i > 0) pos[i]++;
            else if (i == 0) zero++;
            else neg[i]++;
        }

        if (zero % 2) return false;

        for (auto i: pos) {
            auto [num, cnt] = i;
            if (cnt == 0) continue;
            if (pos.find(num * 2) == end(pos) || pos[num * 2] < cnt) {
                return false;
            }
            pos[num * 2] -= cnt;
        }

        for (auto i: neg) {
            auto [num, cnt] = i;
            if (cnt == 0) continue;
            if (abs(num) % 2 == 1 || neg.find(num / 2) == end(neg) || neg[num / 2] < cnt) {
                return false;
            }
            neg[num / 2] -= cnt;
        }

        return true;
    }
};