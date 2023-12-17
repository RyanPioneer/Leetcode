/**
 * Source: is.gd/oaQLQr
 * Date: 2023/12/13
 * Skill:
 * Ref:
 * Runtime: 102 ms, faster than 60.94% of C++ online submissions
 * Memory Usage: 71.89 MB, less than 26.56% of C++ online submissions
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
    int n;
    unordered_map<int, int> mp;
public:
    Solution(int n, vector<int>& blacklist) {
        this->n = n - SZ(blacklist);
        n -= 1;
        unordered_set<int> blacklist_set(begin(blacklist), end(blacklist));
        for (auto &i: blacklist) {
            if (i >= this->n) continue;
            while (blacklist_set.count(n)) n--;
            mp[i] = n--;
        }
    }

    int pick() {
        int idx = rand() % n;
        if (mp.find(idx) == end(mp)) return idx;
        else return mp[idx];
    }
};