/**
 * Source: is.gd/SngiXG
 * Date: 2023/11/24
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 88.65% of C++ online submissions
 * Memory Usage: 10.37 MB, less than 70.92% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e2 + 1;


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0, m = SZ(strs), n = SZ(strs[0]);
        int smaller[MX] = {0}, unfinish = m;
        for (int i = 0; i < n; i++) {
            bool must_delete = false;
            int new_smaller = 0;
            for (int j = 0; j < m - 1; j++) {
                if (smaller[j] == 1) continue;
                if (strs[j][i] > strs[j + 1][i]) {
                    must_delete = true;
                    res++;
                    break;
                }
                if (strs[j][i] < strs[j + 1][i]) {
                    new_smaller++;
                }
            }
            if (!must_delete) {
                unfinish -= new_smaller;
                if (!unfinish) break;
                for (int j = 0; j < m - 1; j++) {
                    if (strs[j][i] < strs[j + 1][i]) {
                        smaller[j] = 1;
                    }
                }
            }
        }
        return res;
    }
};