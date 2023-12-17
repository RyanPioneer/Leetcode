/**
 * Source: is.gd/oaQLQr
 * Date: 2023/12/13
 * Skill:
 * Ref:
 * Runtime: 98 ms, faster than 70.70% of C++ online submissions
 * Memory Usage: 67.02 MB, less than 92.16% of C++ online submissions
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


class Solution {
    int n, pre_space, back;
    vector<int> presum;
public:
    Solution(int n, vector<int>& blacklist) {
        this->n = n - SZ(blacklist);
        if (SZ(blacklist) == 0) {
            back = -1;
            pre_space = 0;
            return;
        }
        sort(begin(blacklist), end(blacklist));
        back = blacklist.back();
        pre_space = back + 1 - SZ(blacklist);
        presum = blacklist;
        for (int i = 0; i < SZ(presum); i++) {
            presum[i] -= i;
        }
    }

    int pick() {
        int idx = rand() % n + 1;
        if (idx > pre_space) {
            return back + idx - pre_space;
        } else {
            auto iter = lower_bound(begin(presum), end(presum), idx);
            int pos = *iter + iter - begin(presum);
            return pos - (*iter - idx + 1);
        }
    }
};