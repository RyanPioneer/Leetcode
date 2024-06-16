/**
 * Source: t.ly/kO9h7
 * Date: 2024/6/1
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 73.74% of C++ online submissions
 * Memory Usage: 11.86 MB, less than 71.22% of C++ online submissions
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


class RLEIterator {
    int pos, sz;
    vector<int> e;
public:
    RLEIterator(vector<int>& encoding) {
        e = encoding;
        pos = 0;
        sz = encoding.size();
    }

    int next(int n) {
        while (pos < sz && e[pos] < n) {
            n -= e[pos];
            pos += 2;
        }
        if (pos == sz) return -1;
        int res = e[pos+1];
        e[pos] -= n;
        if (e[pos] == 0) pos += 2;
        return res;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */