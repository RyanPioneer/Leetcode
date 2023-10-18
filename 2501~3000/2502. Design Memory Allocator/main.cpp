/**
 * Source: twtr.to/5YvU9
 * Date: 2023/10/18
 * Skill:
 * Runtime: 62 ms, faster than 80.86% of C++ online submissions
 * Memory Usage: 31.85 MB, less than 24.88% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Allocator {
    int n;
    unordered_map<int, vector<int>> id2idx;
    unordered_map<int, int> idx2size;
    map<int, int> blocks;
public:
    Allocator(int n) {
        this->n = n;
        blocks[0] = n;
    }

    int allocate(int size, int mID) {
        int sz, idx = -1;
        for (auto i: blocks)
            if (i.second >= size) {
                idx = i.first;
                sz = i.second;
                break;
            }
        if (idx == -1)
            return -1;
        id2idx[mID].push_back(idx);
        idx2size[idx] = size;
        blocks.erase(idx);
        if (sz > size)
            blocks[idx + size] = sz - size;
        return idx;
    }

    int free(int mID) {
        int free_space = 0;
        while (id2idx[mID].size() > 0) {
            int idx = id2idx[mID].back();
            id2idx[mID].pop_back();
            int sz = idx2size[idx];
            free_space += idx2size[idx];
            auto it = blocks.upper_bound(idx);
            if (it != blocks.begin() && prev(it)->first + prev(it)->second == idx) {
                idx = prev(it)->first;
                sz += prev(it)->second;
            }
            if (it != blocks.end() && idx + sz == it->first) {
                sz += it->second;
                blocks.erase(it);
            }
            blocks[idx] = sz;
        }
        return free_space;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */


int main() {
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}